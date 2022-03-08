#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<LL,LL>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
const LL inf=0x3f3f3f3f;
// 昨天没过，又掉分了……
// 现在回想一下，我优先队列里的排序就搞错了，每次增加最大的边不应该是权重和，
// 而应该是被加上的那个数
// 过不了，理解不能……
struct Edg
{
    Edg(LL a=0,LL b=0,LL c=0):u(a),v(b),value(c){};
    LL u,v;
    LL value;
    LL from=-1;//将无向边变成有向，同时标记是否使用过
};

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif

    LL t;
    cin>>t;
    while (t--)
    {
        LL n;
        cin>>n;
        vector<LL> a(n+1);//点的权重
        vector<LL> du(n+1);//点的度数
        LL ans=0;
        for(LL i=1;i<=n;i++){
            cin>>a[i];
            ans+=a[i];
        }
        vector<vector<LL>> link(n+1,vector<LL>());//与每个点相连的边的编号
        vector<Edg> edg(n+1);//所有的边
        for(LL i=1;i<n;i++){//读入n-1条边
            LL u,v;
            cin>>u>>v;
            edg[i]=Edg(u,v,a[u]+a[v]);
            du[u]++;//度数增加
            du[v]++;
            link[u].push_back(i);//与点链接
            link[v].push_back(i);
        }

        auto cmp=[&](const P aa,const P bb)->bool{
            LL v1=edg[aa.y].u;
            if(edg[aa.y].from==v1) v1=edg[aa.y].v;
            LL v2=edg[bb.y].u;
            if(edg[bb.y].from==v2) v2=edg[bb.y].v;
            if(a[v1]==a[v2])
            {
                return du[v1]>du[v2];
            }
            return a[v1]<a[v2];
        };
        priority_queue<P,vector<P>,decltype(cmp)> que(cmp);//(权重、编号)
        for(LL i=1;i<=n;i++)//检查n个点
        {
            if(du[i]==1)//找到边缘点
            {
                for(LL index:link[i])
                    if(edg[index].from==-1){//将没用过的边缘边放入队列
                        edg[index].from=i;
                        que.push(P(edg[index].value,index));
                    }
            }
        }
        cout<<ans<<" ";//1-value
        for(LL o=3;o<=n;o++)
        {
            P tmp=que.top();
            que.pop();
            auto st=edg[tmp.y];
            LL v;//下一个点
            if(st.u==st.from) v=st.v;
            else v=st.u;
            //这条边将被使用，因此减少度数
            du[st.u]--;
            du[st.v]--;
            ans+=a[v];//答案因此增加新点的权值
            cout<<ans<<" ";//o-value
            
            //如果下一个点已经成为边缘点
            if(du[v]==1)
            {
                for(LL index:link[v])
                    if(edg[index].from==-1){//没用过的边缘边
                        edg[index].from=v;
                        que.push(P(edg[index].value,index));
                    }
            }
        }
        cout<<endl;
    }
    return 0;
}

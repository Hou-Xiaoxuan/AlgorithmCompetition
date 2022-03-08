#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<LL,int>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
const LL inf=1e18;
// 简答证明过后，复习dij堆优化的模板题
// 链式前向星版本的dij还是有些不熟练啊
// wc，到底应该是什么类型
// WA10次了，Wa哭了，救救孩子吧
// wcccccccccccccccccc 比较函数用错了，greater才对(将大于当作小于来实现小根堆)
const int N=1e5;
int head[100005],tot;
struct Edg{
    Edg(int v=0,int ne=0,LL w=0,LL bb=0):to(v),next(ne),a(w),b(bb){};
    int to;
    int next;
    LL a;//边权
    LL b;
}edg[200050];
void add(int u,int v,int a,double b){
    edg[++tot]=Edg(v,head[u],a,b);
    head[u]=tot;
}
// 补题： 根据题解，其实就是让最后的等级最小就可以了
// 注意LL
// 本题中，inf的值不够大
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;
        tot=0;
        memset(head,0,sizeof(head));
        int u,v;
        LL a,b;
        for(int i=1;i<=m;i++){
            cin>>u>>v>>a>>b;
            add(u,v,a,LL(1ll<<b)-1);
        }

        // dijstra:
        vector<LL> dis(n+5);//dis[u]极为到达u时候的等级（总权重）
        vector<bool> vis(n+5);
        priority_queue<P,vector<P>,greater<P> > que;//边权和起始点
        for(auto &i:dis) i=inf;
        dis[1]=1;//初始level为1
        que.push(m_p(1ll,1));
        while(!que.empty())
        {
            P st=que.top();
            que.pop();
            int u=st.second;
            if(vis[u]==true) continue;
            vis[u]=true; 
            
            for(int i=head[u];i!=0;i=edg[i].next)
            {
                int v=edg[i].to;
                LL cost=edg[i].a;
                if( cost/dis[u]<edg[i].b ) continue;
                if(dis[v]>dis[u]+cost){
                    dis[v]=dis[u]+cost;
                    que.push(m_p(dis[v],v));
                }
            }
        }
        if(dis[n]==inf) cout<<-1<<endl;
        else cout<<(int)(log2(dis[n]*1.0))<<endl;
    }
    return 0;
}
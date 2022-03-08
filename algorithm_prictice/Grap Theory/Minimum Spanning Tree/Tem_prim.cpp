#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;
// 最小生成树的 prim 实现
//为什么题解都是链式前向星啊！！
//思路：每次选择生成树点到非生成树点的最小边加入生成树，然后更新生成树到所有非生成树的距离
// https://www.luogu.com.cn/problem/P3366
const int M=4e5+5;
const int N=1e5;
// 链式前向星存图，也相当于板子了……
int head[N],tot=0;
struct edge{
    edge():next(0){};
    int to;
    int next;
    int value;
}edg[M];
void addEdge(int u,int v,int value){
    edg[++tot].to=v;
    edg[tot].value=value;
    edg[tot].next=head[u];
    head[u]=tot;
}
//prim
priority_queue<P,vector<P>,greater<P> > que;//默认first优先
int lowest[N];//树 到i的最短距离
bool vis[N]={false};
LL prim(int n)
{
    memset(lowest,127,sizeof(int)*(n+1));
    memset(vis,0,sizeof(bool)*(n+1));
    LL cnt=0,sum=0;
    que.push(m_p(0,1));

    while(!que.empty() and cnt<n)
    {
        int u=que.top().second,tmp_value=que.top().first;
        que.pop();
        if(vis[u]==false)
        {
            cnt++;//树上新增一个节点
            sum+=tmp_value;
            vis[u]=true;
            for(int i=head[u];i;i=edg[i].next)
                if(edg[i].value<lowest[edg[i].to])
                {
                    lowest[edg[i].to]=edg[i].value;
                    que.push(m_p(edg[i].value,edg[i].to));
                }
        }        
    }
    if(cnt==n) return sum;
    else return -1;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_prictice\\in.txt","r",stdin);  
    #endif
    
    int n,m;
    cin>>n>>m;
    int u,v,w;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
    LL ans=prim(n);
    if(ans==-1) cout<<"orz"<<endl;
    else cout<<ans<<endl;

    return 0;
}

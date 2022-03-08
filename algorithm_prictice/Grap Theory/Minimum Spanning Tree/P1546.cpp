// https://www.luogu.com.cn/problem/P1546
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

//Ê¹ÓÃprim½â´ð
const int M=1e5+5;
const int N=1e5;
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
priority_queue<P,vector<P>,greater<P> > que;
int lowest[N];
bool vis[N];
LL prim(int n)
{
    memset(lowest,127,sizeof(int)*105);
    memset(vis,false,sizeof(bool)*105);

    que.push(m_p(0,1));
    LL ans=0,cnt=0;
    while(!que.empty() and cnt<n)
    {
        int u=que.top().second,tmp=que.top().first;
        que.pop();
        if(vis[u]==false)
        {
            vis[u]=true;
            ans+=tmp;
            cnt++;
            for(int i=head[u];i;i=edg[i].next)
                if(edg[i].value<lowest[edg[i].to]){
                    lowest[edg[i].to]=edg[i].value;
                    que.push(m_p(edg[i].value,edg[i].to));
                }
        }
    }
    return ans;
}
void solve()
{
    int n;
    cin>>n;
    int w;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            {
                cin>>w;
                if(i!=j) addEdge(i,j,w);
            }
    cout<<prim(n)<<endl;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_prictice\\in.txt","r",stdin);  
    #endif
    
    solve();

    return 0;
}
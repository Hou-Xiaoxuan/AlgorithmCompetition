#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long long LL;
typedef pair<int,int> P;
#define m_p make_pair
#define x first
#define y second
const int inf=0x3f3f3f3f;
int edg[2005][2005];
struct node
{
    node():a(0,0),b(0,0),w(inf){};
    node(int a1,int a2,int b1,int b2,int ww):a(a1,a2),b(b1,b2),w(ww){};
    P a;
    P b;
    int w;
};
node dot[2005];

int dij(int u,int k)
{
    priority_queue<P, vector<P>, greater<P> > que;
    vector<int> dis(k+5);
    vector<bool> vis(k+5);
    dis[0]=0;
    // 暴力版本
    // for(int i=0;i<=k+1;i++) dis[i]=edg[0][i];
    // for(int i=1;i<=k+1;i++)
    // {
    //     int v=0,minn=inf;
    //     for(int j=1;j<=k+1;j++)
    //     {
    //         if(vis[j]==false and dis[j]<minn){
    //             minn=dis[j];
    //             v=j;
    //         }
    //     }
    //     vis[v]=true;
    //     for(int j=1;j<=k+1;j++)
    //     {
    //         dis[j]=min(dis[j],dis[v]+edg[v][j]);
    //     }
    // }

    // 优化版本
    for(int i=1;i<=k+1;i++) dis[i]=inf;
    que.push(m_p(0,0));
    while(!que.empty())
    {
        int u=que.top().second;
        que.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=1;i<=k+1;i++)
        {
            if(dis[i]>=dis[u]+edg[u][i])
            {
                dis[i]=dis[u]+edg[u][i];
                que.push(m_p(dis[i],i));
            }
        }
    }
    if(dis[k+1]==inf) cout<<"-1"<<endl;
    else cout<<dis[k+1]<<endl;
}

int main()
{
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif

    int t;cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int x1,y1,x2,y2,w;
        for(int i=1;i<=n;i++){
            cin>>x1>>x2>>y1>>y2>>w;
            dot[i]=node(x1,x2,y1,y2,w);
            
        }
        memset(edg,0x3f,sizeof(edg));
        for(int i=1;i<=k;i++)
            for(int j=1;j<=k;j++)
            {
                if( dot[i].a.y-dot[i].a.x+dot[j].a.y-dot[j].a.x+1 >= max(abs(dot[i].a.x-dot[j].a.y),abs(dot[i].a.y-dot[j].a.x) ))
                if( dot[i].b.y-dot[i].b.x+dot[j].b.y-dot[j].b.x+1 >= max(abs(dot[i].b.x-dot[j].b.y),abs(dot[i].b.y-dot[j].b.x)) )
                    edg[i][j]=dot[j].w;
            }
        int ans=0;
        for(int i=1;i<=k;i++)
        {
            if(dot[i].a.x==1 or dot[i].b.y==m) edg[0][i]=dot[i].w;
            else if(dot[i].b.x==1 or dot[i].a.y==n) edg[i][k+1]=0;
        }   
        dij(0,k);
    }
    return 0;
}
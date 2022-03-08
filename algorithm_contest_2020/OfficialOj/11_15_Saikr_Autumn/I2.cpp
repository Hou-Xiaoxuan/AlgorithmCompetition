#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
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
// 错的
const int N=1e3+5;
const int M=1e6;
int head[N],cnt=0;
struct edge{
    int to;
    int from;
    int value;
    int index=0;//表示边是属于哪一个环
    int ct=0;//表示边的编号
    bool operator<(const edge&s){
        return value<s.value;
    }
}edg[M];

int fa[N];
struct cmp
{
    bool operator()(const int a,const int b){
        return edg[a].value<edg[b].value;
    }
};
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif

    int n;
    cin>>n;

    int u,v,w;
    int m=n*(n-1)/2;
    vector<vector<int> > node(n+1,vector<int>());
    priority_queue<int,vector<int>,cmp> que_init;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        edg[i].ct=i;
        edg[i].from=u;
        edg[i].to=v;
        edg[i].index=0;
        edg[i].value=w;
        node[u].push_back(i);
        node[v].push_back(i);
        que_init.push(i);
    }
    
    int t=(n-1)/2+1;
    while((--t)!=1)
    {
        priority_queue<int,vector<int>,cmp> que;
        // init();
        while(!que_init.empty() and  edg[que_init.top()].index!=0) que_init.pop();
        que.push(que_init.top());
        que_init.pop();
        vector<int> vis(n+1);
        while(!que.empty())
        {
            edge st=edg[que.top()];
            que.pop();
            if(st.index!=0) continue;
            if(vis[st.from]==2 or vis[st.to]==2) continue;

            edg[st.ct].index=t;
            vis[st.from]++;
            vis[st.to]++;
            if(vis[st.from]!=2)
            {
                for(auto u:node[st.from])
                    if(edg[u].index==0)
                        que.push(u);
            }
            if(vis[st.to]!=2)
            {
                for(auto u:node[st.from])
                    if(edg[u].index==0)
                        que.push(u);
            }
        }
    }

    vector<vector<int> > num((n+1)/2,vector<int>(n+1));
    for(int i=1;i<=cnt;i++)
    {
        auto &st=edg[i];
        num[st.index][st.to]=max(num[st.index][st.to],st.value);
        num[st.index][st.to]=max(num[st.index][st.to],st.value);
    }
    LL ans=0;
    for(int i=1;i<=(n-1)/2;i++)
        for(int j=1;j<=n;j++)
            ans+=num[i][j];
    cout<<ans;
    return 0;
}

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
// 错的，我实现不下去了……
const int N=1e3+5;
const int M=1e6;
int head[N],cnt=0;
struct edge{
    edge():next(0){};
    int to;
    int from;
    int next;
    int value;
    int index=0;//表示边是属于哪一个环
    int ct=0;//表示边的编号
    bool operator<(const edge&s){
        return value<s.value;
    }
}edg[M];
void add_edge(int u,int v,int value){
    edg[++cnt].to=v;
    edg[cnt].from=u;
    edg[cnt].value=value;
    edg[cnt].next=head[u];
    edg[cnt].ct=cnt;
    head[u]=cnt;
}

int fa[N];

int find(int x) {
    return fa[x] < 0 ? x : (fa[x] = find(fa[x])); // 查询
}
bool merge(int u, int v) {
    int x = find(u), y = find(v);
    if (x == y)
        return false;
    if (fa[x] < fa[y])
        fa[y] = x, fa[x] = min(fa[y] - 1, fa[x]); //按秩合并
    else
        fa[x] = y, fa[y] = min(fa[x] - 1, fa[y]);
    return true;
}

void init() {
    memset(fa, -1, sizeof(fa)); //！！！初始化
}

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
    for(int i=1;i<=n*(n+1)/2;i++)
    {
        cin>>u>>v>>w;
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    int t=(n-1)/2;
    while(t--)
    {
        init();
        edge st;
        for(int i=1;i<=cnt;i++){
            if(edg[i].index==0)
                st=max(st,edg[i]);//找最大值
        }
        priority_queue<edge> que;
        que.push(st);
        while(!que.empty())
        {
            st=que.top();
            que.pop();
            if(find(st.from)==find(st.to)) continue;
            // 被环使用了，连接+标记
            merge(st.from,st.to);
            edg[st.ct].index=t;
            for(int u=head[st.from];u;u=edg[u].next)
            {
                if(edg[u].index!=0) continue;
                que.push(edg[u]);
            }

            for(int u=head[st.to];u;u=edg[u].next)
            {
                if(edg[u].index!=0) continue;
                que.push(edg[u]);
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
    cout<<endl;
    return 0;
}

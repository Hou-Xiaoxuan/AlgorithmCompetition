//网络流常用算法，在FF暴力算法的基础上做了一定的优化
// 使用bfs的层数来限制搜索路径的长度，避免绕远路
// 有四部分，dfs，bfs，算法执行，数据读入
// 使用当前弧优化，否则查询太多重复边，时间差距很大 2200ms->16ms
// 由于当前弧已经起到剪枝的作用了，vis加不加影响不大。
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
const LL LLinf=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
// AC模板
struct Edg{
    Edg(int vv=0,LL ww=0,int rr=0):v(vv),w(ww),rev(rr){};
    int v;
    LL w;
    int rev;//储存反向边的编号
};
vector<vector<Edg>> edg;//邻接表存边
vector<int> degree;//BFS的层次
vector<int> current;//当前弧优化，减少“废”边的遍历,记录当前节点遍历到边的编号。
bool BFS(int source,int target)
{
    degree.assign(edg.size(),0);
    queue<int> que;
    que.push(source);
    degree[source]=1;
    while(!que.empty())
    {
        int st=que.front();
        que.pop();
        for(Edg e:edg[st])
        {
            if(e.w>0 and degree[e.v]==0)
            {
                degree[e.v]=degree[st]+1;
                que.push(e.v);
            }
        }
    }
    return degree[target]!=0;//返回图源点和汇点是否连通。
}
LL dfs(int u,int target,LL sum)
{
    if(u==target) return sum;
    for(int &i=current[u];i<edg[u].size();i++)//这里的i作为当前弧优化要用 引用
    {
        Edg &e=edg[u][i];
        if(e.w>0 and (degree[u]+1)==degree[e.v])//限制条件：相差一层
        {
            LL tmp=dfs(e.v,target,min(sum,e.w));
            if(tmp>0)
            {
                e.w-=tmp;
                edg[e.v][e.rev].w+=tmp;//反向边增加
                return tmp;//直接返回，i没有更新，后续仍然可以访问该节点
            }
        }
    }
    degree[u]=-1;//当前节点废了，炸点优化，不再使用该点(没啥实际作用)
    return 0;
}
LL Dinic(int source,int target)
{
    //执行BFS直到不连通，最多n次
    LL flow=0;
    while(BFS(source,target)==true)
    {
        current.assign(edg.size(),0);
        LL increment=0;
        do
        {
            increment=dfs(source,target,LLinf);
            flow+=increment;
        } while (increment!=0);
    }
    return flow;
}

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #elif _LINUX
    freopen("/media/linxuan/储存/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("/media/linxuan/储存/CODE/algorithm_contest/in.txt","r",stdin);
    #endif
    
    int n,m,source,target;
    cin>>n>>m>>source>>target;
    edg.assign(n+1,vector<Edg>());
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edg[u].push_back(Edg(v,w,edg[v].size()));
        edg[v].push_back(Edg(u,0,edg[u].size()-1));
    }

    LL ans = Dinic(source,target);
    cout<<ans<<endl;
    return 0;
}

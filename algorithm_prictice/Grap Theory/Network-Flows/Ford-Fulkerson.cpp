// 网络流的ff算法模板……没有优化的情况下非常容易被卡
// 不断进行深搜，直到不存在增广路
// 非常容易被卡，但是是其他算法的基础
// 主要由三部分组成，dfs，算法调用，数据的读入。其中在dfs中要维护数据
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
const LL inf=0x3f3f3f3f3f3f3f3f;
// 洛谷模板题TLE 2个点
struct Edg{
    Edg(int vv=0,LL ww=0,int rr=0):v(vv),w(ww),rev(rr){};
    int v;
    LL w;
    int rev;//储存反向边的编号
};
vector<vector<Edg>> edg;//邻接表存边
vector<bool> vis;//dfs时标记点的遍历情况
LL dfs(int u,int target,LL num)
{
    if(u==target)
        return num;
    vis[u]=true;//标记使用过了，不去要去除标记
    for(Edg& e:edg[u])
    {
        if(vis[e.v]==false and e.w>0) //查询没用过的点，边权为0即不存在
        {
            LL tmp=dfs(e.v,target,min(num,e.w));//最大流有最小容量和最大流量限制
            if(tmp>0)//成功找到增广路
            {
                e.w-=tmp;
                edg[e.v][e.rev].w+=tmp;//反向边增加
                return tmp;
            }
        }
    }
    return 0;
}
LL Ford_Fulkeson(int source,int target)
{
    LL flow=0;
    LL increment=0;
    do{
        vis.assign(edg.size()+1,0);
        increment=dfs(source,target,inf);
        flow+=increment;
    }while(increment!=0);
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

    LL ans = Ford_Fulkeson(source,target);
    cout<<ans<<endl;
    return 0;
}

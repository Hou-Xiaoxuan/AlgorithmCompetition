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
// 树的重心 模板
const int N=1e5+5;
int son[N];//去掉u后的最大连通数目，取 n-siz[u]和子节点的siz的最大值
int siz[N];//以u为根的节点数目
bool vis[N];
vector<int> edg[N];
int n;
int dfs(int u)
{
    int cnt=0;
    for(auto &v:edg[u])
    {
        if(vis[v]==false)
        {
            vis[v]=true;
            cnt+=dfs(v);
        }
    }
    siz[u]=cnt+1;
    son[u]=max(son[u],n-siz[u]);
    for(auto&v:edg[u])
        son[u]=max(son[u],siz[v]);
    return siz[u];
}
 //遍历son[i]找最小值就可以了
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_prictice\\in.txt","r",stdin); 
    #endif
    
    //遍历son[i]找最小值就可以了
    return 0;
}
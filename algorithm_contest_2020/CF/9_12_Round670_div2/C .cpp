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
// 去求树的直径就可以了
const int N=1e5+5;
vector<int> edg[N];
int num[N];//以u为根的子树个数
int son[N];//上去u后的最大联通
bool vis[N];
int maxdot;
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
    num[u]=cnt+1;
    son[u]=max(son[u],n-num[u]);
    for(auto&v:edg[u])
        son[u]=max(son[u],num[v]);
    return num[u];
}
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
        cin>>n;
        for(int i=0;i<=n;i++)
            edg[i].clear();

        int u,v;
        for(int i=1;i<n;i++){
            cin>>u>>v;
            edg[u].push_back(v);
            edg[v].push_back(u);
        }
        memset(vis,0,sizeof(bool)*(n+1));
        memset(num,0,sizeof(int)*(n+1));
        memset(son,0,sizeof(int)*(n+1));
        vis[1]=true;
        dfs(1);
        int son1=0,son2=0;
        int minn=inf;
        for(int i=1;i<=n;i++)
        {
            if(son[i]<minn) {
                son1=i;
                son2=0;
                minn=son[i];
            }
            else if(son[i]==minn) son2=i;
        }
        if(son2==0)
        {
            cout<<son1<<' '<<edg[son1][0]<<endl;
            cout<<son1<<' '<<edg[son1][0]<<endl;
        }
        else
        {
            for(auto &v:edg[son2])
                if(v!=son1){
                    u=v;
                    break;
                }
            cout<<son2<<" "<<u<<endl;
            cout<<u<<" "<<son1<<endl;
        }
        
    }
    return 0;
}
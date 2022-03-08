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

const int N=1e5+5;
vector<int> edg[N];//存边
int dis[N];//所有的点到搜索点的距离
int n,a,b,da,db;
int maxdis,maxdot;
void dfs(int u)
{
    // 树中没有环
    if(dis[u]>maxdis){
        maxdis=dis[u];
        maxdot=u;
    }
    for(auto v:edg[u])
    {
        if(dis[v]==-1){
            dis[v]=dis[u]+1;
            dfs(v);
        }
    }
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
        cin>>n>>a>>b>>da>>db;
        int u,v;
        for(int i=0;i<=n+2;i++) edg[i].clear();
        for(int i=1;i<n;i++){
            cin>>u>>v;
            edg[u].push_back(v);
            edg[v].push_back(u);    
        }
        // 搜索各点到a的距离
        memset(dis,-1,sizeof(int)*(n+5));
        dis[a]=0;
        maxdis=0;
        dfs(a);
        if(dis[b]<=da){//一步到位
            cout<<"Alice"<<endl;
            continue;
        }
        memset(dis,-1,sizeof(int)*(n+5));
        dis[maxdot]=0;
        maxdis=0;
        dfs(maxdot);
        // 现在，maxdis就是树的直径
        if(da*2>=maxdis){
            cout<<"Alice"<<endl;
            continue;
        }
        if(db>2*da)
            cout<<"Bob"<<endl;
        else if(db<=da*2){
            /*Alice and Bob 的距离一定在接近。一旦Alice到Bob的距离缩短到da，Bob将无路可走。
            *继续退后，距离还是会被缩短到da。越过Alice到另外一边的话，两人的距离将未db-da<=da,被捕获
            * */
            cout<<"Alice"<<endl;
        }
    }
   
    return 0;
}
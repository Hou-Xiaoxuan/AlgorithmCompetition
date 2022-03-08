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

// 关于树上的问题，还是去年CF看过一点啊……统计子节点个数后的操作完全不会
// 啊啊啊，放弃了，感觉思路是对了，但是实现差一点啊！！
// 算了，这题太难了，废了
const int N=4e2+5;
vector<int> edg[N];
int num[N]={0};
int fin[N];//
int ct=0;
bool vis[N]={0};
int ans[N]={0};
int n;
int dfs(int u)
{
    int cnt=0;
    vis[u]=true;
    for(int i=0;i<edg[u].size();i++)
    {
        if(vis[edg[u][i]]==false){
            cnt+=dfs(edg[u][i]);
        }
    }
    vis[u]=false;
    fin[cnt+1]++;
    return num[u]=cnt+1;
}
// 改一下 dfs2应该可以的
// void dfs2(int u)
// {
//     bool flag=true;
//     int dot=-1;
//     for(int v=0;v<edg[u].size();v++)
//     {
        
//         if(num[v]<=n/2) continue;
//         else{
//             dot=v;
//             break;
//         }
//     }
//     // 验证
//     if(dot!=-1)
//     {
//         for(int v=0;v<edg[u].size();v++)
//         {
//             if(v!=dot) fin[num[v]]--;
//         }
//         flag=false;
//         int m=num[dot]-n/2;
//         for(int j=m;j<=n/2;j++)
//             if(fin[j]>0){
//                 flag=true;
//                 break;
//             }
//         for(int v=0;v<edg[u].size();v++)
//         {
//             if(v!=dot) fin[num[v]]++;
//         }
//     }
//     if(flag==true) ans[u]=1;
//     else ans[u]=0;
// }

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    dfs(1);
    dfs2(1);
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}

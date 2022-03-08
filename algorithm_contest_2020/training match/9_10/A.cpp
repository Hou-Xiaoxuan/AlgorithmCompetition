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
bool vis[5000]={0}; 
int ans[5000]={0};
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    vis[1]=1;
    for(int i=2;i<=4000;i++)
    {
        if(vis[i]==0)
        {
            ans[i]++;
            for(int j=i*2;j<=4000;j+=i){
                vis[j]=1;
                ans[j]++;
            }
        }
    }
    int n;
    while(cin>>n)
    {
        int cnt=0;
        for(int i=1;i<=n;i++) if(ans[i]==2)  cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}
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


int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif

    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a.begin(),a.end());
        vector<bool> vis(2*n+1);
        int ans=0;
        vis[0]=true;
        for(int i=1;i<=n;i++)
        {
            if(vis[a[i-1]]==false){
                vis[a[i]-1]=true;
                ans++;
            }
            else if(vis[a[i]]==false){
                vis[a[i]]=true;
                ans++;
            }
            else if(vis[a[i]+1]==false){
                vis[a[i]+1]=true;
                ans++;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}

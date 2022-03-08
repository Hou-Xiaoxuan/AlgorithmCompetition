//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1005;
int f[N][N],v[N],w[N],dp[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
     int n,m;
     while(cin>>n>>m)
    {
        memset(v,0,sizeof(v));
        memset(w,0,sizeof(w));
        //for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
        for(int i=1;i<=n;i++) cin>>v[i];
        for(int i=1;i<=n;i++) cin>>w[i];
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
            for(int j=0;j<=m;j++){//为什么 航电oj 不过呢？原因是j可以取0，而方程未体现
                if(j>=w[i]) f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+v[i]);
                else f[i][j]=f[i-1][j];
            }
        int ans=-1;
        for(int i=0;i<=m;i++) ans=max(ans,f[n][i]);
        cout<<ans<<endl;     
       /*AC
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            for(int j=m;j>=w[i];j--)//压到一维时不许倒序
                dp[j]=max(dp[j-w[i]]+v[i],dp[j]);
        cout<<dp[m]<<endl;
        */
    }
    return 0;
}
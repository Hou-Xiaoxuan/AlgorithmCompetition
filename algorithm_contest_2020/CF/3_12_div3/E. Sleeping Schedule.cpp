//被c题和d题坑了，c是道水题，d报进度了
//时间不够了，但是这道题貌似可以补……明天补题，疑似DP
//题解: DP[i][j]表示 前i个在时间j醒来的最大满意值，类似01背包
#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005],a[2005];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    int n,h,l,r;
    cin>>n>>h>>l>>r;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=h;j++)
            dp[i][j]=-1;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<h;j++){ 
               dp[i][j]=max(dp[i-1][(j-(a[i]-1)+h)%h],dp[i-1][(j-a[i]+h)%h]);
               if(j>=l and j<=r and dp[i][j]!=-1) dp[i][j]++;//必须合法才能++，不然结果偏大
           }
    int ans=0;
    for(int i=0;i<=h;i++)
        ans=max(ans,dp[n][i]);
    cout<<ans<<endl;
    return 0;
}
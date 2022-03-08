#include<bits/stdc++.h>
using namespace std;
//²¹Ìâ£ºãÂãÂ¶®¶®
int main()
{
    int dp[27][27]={0};
    int n;cin>>n;
    char s[20];
    while(n--)
    {
        cin>>s;
        int v=s[0]-'a',u=s[strlen(s)-1]-'a';
        for(int i=0;i<26;i++)
            if(dp[i][v]==0) continue;
            else dp[i][u]=max(dp[i][u],dp[i][v]+int(strlen(s)) );
        dp[v][u]=max(dp[v][u],int(strlen(s)));          
    }
    int ans=0;
    for(int i=0;i<26;i++)    
            ans=max(ans,dp[i][i]);
    cout<<ans<<endl;
    return 0;
}
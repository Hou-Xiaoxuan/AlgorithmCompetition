//可笑你竟然根本没有读懂题，kmp+dp
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
const int N=2e7+100;
const int mod=10007;
char s[N];
int kmp[N],dp[N];
int main()
{
    scanf("%s",s+1);
    int j=0,len=strlen(s+1);
    kmp[1]=0;
    for(int i=2;i<=len;i++){
        while(j and s[j+1]!=s[i]) j=kmp[i];
        if(s[j+1]==s[i]) j++;
        kmp[i]=j;
    }
    for(int i=1;i<=len;i++) dp[i]=1;
    for(int i=len;i>=1;i--){
        dp[kmp[i]]=(dp[i]+dp[kmp[i]])%mod;
    }
    LL ans=0;
    for(int i=1;i<=len;i++){
       ans=(ans+i*dp[i])%mod;
    }
    cout<<ans<<endl;
    return 0;
}
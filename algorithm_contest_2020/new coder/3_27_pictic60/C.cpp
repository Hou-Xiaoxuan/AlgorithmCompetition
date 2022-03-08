#include<bits/stdc++.h>
using namespace std;
#define make_pair m_k
typedef long long LL;
typedef unsigned long long ULL;
//补题：dp+去重，统计dp[i][j]//前i个长度j的子序列个数 只需要减去 dp【s【i】上次出现】【j】就行了
char s[1005];
LL dp[1005][1005]={0};
const LL mod=1e9+7;
int main()
{
    
    int n,k;cin>>n>>k;
    cin>>s+1;
    int pre[30]={0};
    dp[0][0]=1;//默认空字符算1
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++){
            dp[i][0]=1;
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];//选择第i个与不选择第i个的和就是重复的总数，重复出现在选择i里面
            if(pre[s[i]-'a']!=0) dp[i][j]-=dp[pre[s[i]-'a']-1][j-1];//只要去掉上一次出现is[i]时长度为j时选择了s[i]d数量
            dp[i][j]%=mod;//因为上一次出现的这一次一定会计算一遍，出现重复
        }
        pre[s[i]-'a']=i;//s[i]上次出现的位置
    }
    LL ans=dp[n][k];
    if(ans<0) ans+=mod;
    cout<<ans<<endl;
    return 0;
}

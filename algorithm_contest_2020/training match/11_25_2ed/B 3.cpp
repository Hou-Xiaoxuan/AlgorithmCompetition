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
const LL inf=0x3f3f3f3f3f3f3f3f;

// 区间DP
// AC
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif

    int n;
    while(cin>>n)
    {
        LL d,c;
        cin>>d>>c;
        vector<ULL> dp(n+1,inf),a(n+1),sum(n+1);//dp[i]
        // 使用前缀和维护更新
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
        }
        dp[0]=0;
        for(int i=1;i<=n;i++)
            for(int j=0;j<i;j++)
            {
                dp[i]=min(dp[i], dp[j]+(LL(i-j)*a[i]-sum[i]+sum[j])*c+d );
            }
        cout<<dp[n]<<endl;
    }
    return 0;
}

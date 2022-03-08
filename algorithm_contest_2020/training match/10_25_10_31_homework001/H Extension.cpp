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
// 思路：DP+容斥
/*
*题目解析：第三行是选择一块涂黑，剩下的全部涂白
*重复的是黑色不放在角落的情况数目
*/
LL dp[3005][3005];
LL mod=998244353;
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    int a,b,c,d;
    while(cin>>a>>b>>c>>d)
    {
        memset(dp,0,sizeof(dp));
        dp[a][b]=1;
        for(int i=a;i<=c;i++)
            for(int j=b;j<=d;j++)
            {
                if(i==a and j==b) continue;
                dp[i][j]=( dp[i-1][j]*j%mod + dp[i][j-1]*i%mod - (i-1)*(j-1)%mod*dp[i-1][j-1]%mod+mod )%mod;
            }
        cout<<dp[c][d]<<endl;
    }
    return 0;
}
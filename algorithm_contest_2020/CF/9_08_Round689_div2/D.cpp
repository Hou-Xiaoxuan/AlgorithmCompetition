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
const int N=3e5+5;
int dp[N];
// 本题是比较只管的一维DP。但是转移的路径不好求。要用到单调栈。
// 在单调栈的退栈过程中，所有被弹出的点与这个点之间的所有点都大于/小于这两个点，因此可以跳
// 题解链接：https://blog.csdn.net/qq_45458915/article/details/108486352
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
        vector<int> a(n+1);
        memset(dp,0x3f,sizeof(dp));
        for(int i=1;i<=n;i++) cin>>a[i];
        dp[1]=0;
        stack<int> sta1,sta2;
        sta1.push(1);
        sta2.push(1);
        for(int i=2;i<=n;i++)
        {
            bool flag=false;
            while(sta1.size() and a[i]<=a[sta1.top()]){
                if(a[i]==a[sta1.top()]) flag=true;
                dp[i]=min(dp[i],dp[sta1.top()]+1);
                sta1.pop();
            }
            // 如果出现了相等，则栈顶不合法。否则合法
            if(sta1.size() and !flag) dp[i]=min(dp[i],dp[sta1.top()]+1);

            flag=false;
            while(sta2.size() and a[i]>=a[sta2.top()]){
                if(a[i]==a[sta2.top()]) flag=true;
                dp[i]=min(dp[i],dp[sta2.top()]+1);
                sta2.pop();
            }
            // 如果出现了相等，则栈顶不合法。否则合法
            if(sta2.size() and !flag) dp[i]=min(dp[i],dp[sta2.top()]+1);

            sta1.push(i);
            sta2.push(i);
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
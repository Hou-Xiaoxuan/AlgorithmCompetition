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
LL mod=1e9+7;
LL qpow(LL a,LL b,LL m=mod){
    LL ans=1;
    LL k=a;
    while(b){
        if(b&1)ans=ans*k%m;
        k=k*k%m;
        b>>=1;
    }
    return ans;
}
// 线性代数 签到
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int n,x;
    while(cin>>n>>x)
    {
        vector<LL> a(n+1),b(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        LL ans=qpow(x,n-1);
        LL tmp=0;
        for(int i=1;i<=n;i++)
        {
            tmp+=(a[i]*b[i])%mod;
        }
        tmp+=x;
        ans=((ans%mod)*(tmp%mod))%mod;
        cout<<ans<<endl;
    }
    return 0;
}
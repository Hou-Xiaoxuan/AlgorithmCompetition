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

// LL qpow(LL a,LL b,LL m){
//     LL ans=1;
//     LL k=a;
//     while(b){
//         if(b&1)ans=ans*k%m;
//         k=k*k%m;
//         b>>=1;
//     }
//     return ans;
// }
inline LL qpow(LL x, LL y,LL mod)
{
    LL ans = 1;
    while(y)
    {
        if(y&1) ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif

    int t;cin>>t;
    while(t--)
    {
        LL n,k;
        cin>>n>>k;
        if(k&1){
            cout<<0<<endl;
            continue;
        }
        vector<LL> C(k+1);
        const LL mod=1e9+7;

        // 求1~k下%mod的逆元
        vector<LL> inv(k+1);
        inv[1]=1;
        for(int i=2;i<=k;i++)
        {
            inv[i]=(mod-mod/i)*inv[mod%i]%mod;
        }
        // 求C(n,i)
        C[1]=n;
        for(int i=2;i<=k;i++)
        {
            C[i]=((k-i+1)*C[i-1])%mod*inv[k];
            C[i]%=mod;
        }
        // 如何确定C的数量呢？根据n的不同,c的个数不同，但是没相邻的k个里面一定是k/2个，最后n%k个怎么计数？
        // k中前n%k里c的个数
        LL ans=qpow(2,(n/k)*k/2,mod);
        LL m=n%k;
        vector<LL> C_m(k+1),C_km(k+1);
        C_m[1]=m; C_m[0]=1;
        C_km[1]=k-m; C_km[0]=1;
        for(int i=2;i<=m;i++)
        {
            C_m[i]=((m-i+1)*C_m[i-1])%mod*inv[m];
            C_m[i]%=mod;
        }
        for(int i=2;i<=k-m;i++)
        {
            C_km[i]=((k-m-i+1)*C_km[i-1])%mod*inv[k-m];
            C_km[i]%=mod;
        }
        LL tmp=0;
        // C_m[i]*C_km[k/2-i]为存在i个c的数量，综合一定为C[k/2]
        for(int i=max(0ll,m-k/2);i<=min(m,k/2);i++)
        {
            tmp+=C_m[i]*C_km[k/2-i]*qpow(2,m-i,mod);
        }
        if(m==0) ans*=C[k/2];
        else ans*=tmp;
        ans%=mod;
        cout<<ans<<endl;

    }
    return 0;
}

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
// AC
LL qpow(LL a,LL b,LL m){
    LL ans=1;
    LL k=a;
    while(b){
        if(b&1)ans=ans*k%m;
        k=k*k%m;
        b>>=1;
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
    const int M=1e5;
    const LL mod=1e9+7;
    // 初始化阶乘和乘法逆元
    vector<LL> fac(M+5);
    fac[0]=1;
    for(int i=1;i<=M;i++)
        fac[i]=fac[i-1]*i%mod;
    vector<LL> inv(M+5);
    inv[0]=1;
    for(int i=1;i<=M;i++)
        inv[i]=qpow(fac[i],mod-2,mod);
    function C=[&](LL n,LL m)->LL{
        return fac[n]*inv[m]%mod*inv[n-m]%mod;
    };
    int t;cin>>t;
    while(t--)
    {
        LL n,k;
        cin>>n>>k;
        if(k&1){
            cout<<0<<endl;
            continue;
        }
        LL ans=0;
        LL m=n%k,a=n/k,b=n-a*k;
        // (2, (a + 1) * (b - i) + a * (k - b - k / 2 + i))
        for(int i=max(0ll,m-k/2);i<=min(m,k/2);i++)
            ans+=C(m,i)*C(k-m,k/2-i)%mod*qpow(2,(2, (a + 1) * (b - i) + a * (k - b - k / 2 + i)),mod)%mod;//傻逼忘记取模了
        cout<<(ans+mod)%mod<<endl;
    }
    return 0;
}

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define x first
#define y second 
using namespace std;
using LL=long long;
using ULL=unsigned long long;
using LD=long double;
using P=pair<int,int>;
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;
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
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #endif
    const int M=1005;
    const int mod=1e9+7;
    vector<LL> fac(M+1);
    vector<LL> inv(M+1);
    fac[0]=inv[0]=1;
    for(int i=1;i<=M;i++)
        fac[i]=fac[i-1]*i%mod;
    inv[1]=1;
    for(int i=1;i<=M;i++)
        inv[i]=qpow(fac[i],mod-2,mod);
    function<LL(LL,LL)> C=[&](LL n,LL m)->LL{
        return fac[n]*inv[m]%mod*inv[n-m]%mod;
    };
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a.begin()+1,a.end(),greater<int>());

        int val=a[k];
        int cnt[2]={0};
        for(int i=1;i<=n;i++){
            if(a[i]==val) cnt[1]++;
            if(a[i]==val and i<=k) cnt[0]++;
        }
        cout<<C(cnt[1],cnt[0])%mod<<endl;
    }
    return 0;
}

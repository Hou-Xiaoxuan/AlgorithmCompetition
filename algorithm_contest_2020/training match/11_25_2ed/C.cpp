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
/*
4
0 1 2 3
5
1 1 2 1 1
13
1 2 3 4 5 6 7 8 9 10 11 12 13
*/
// 全排列(首不最小、尾不最大)-有序
// 我错了，好难啊
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
    const int mod=1e9+9;
    vector<LL> fac(M+5);
    fac[0]=1;
    for(int i=1;i<=M;i++)
        fac[i]=fac[i-1]*i%mod;
    vector<LL> inv(M+1);
    inv[1]=1;
    inv[0]=1;
    for(int i=1;i<=M;i++)
        inv[i]=qpow(fac[i],mod-2,mod);
    function C=[&](LL n,LL m)->LL{
        return fac[n]*inv[m]%mod*inv[n-m]%mod;
    };
    function A=[&](LL n,LL m)->LL{
        return fac[n]*inv[n-m]%mod;
    };
    int n;
    while(cin>>n)
    {
        map<int,int> ma;
        int x;
        int maxn=-1,minn=1e9+1;
        for(int i=1;i<=n;i++){
            cin>>x;
            maxn=max(maxn,x);
            minn=min(minn,x);
            ma[x]++;
        }
        LL ans=0;
        // 有点小复杂
        if(ma.size()>=2)
        {
            int l=ma[minn],r=ma[maxn];
            if(ma.size()>2) ans=A(n-l-r,l)%mod*A(n-l-r,r)*A(n-l-r,n-l-r);//头部不放尾节点
            ans+=A(r,r)*A(n-r,n-r);//头部使用尾节点
            ans%=mod;
            // 去重
            LL tmp=1;
            for(auto i:ma){
                tmp*=fac[i.second];
            }
            ans-=tmp-1;
            ans=(ans+mod)%mod;
        }
        else ans=0;
        cout<<ans<<endl;
    }
    return 0;
}

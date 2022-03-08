#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;
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
    //freopen("D:\\CODE\\code_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_contest\\in.txt","r",stdin);  
    #endif
    int t;cin>>t;
    const LL mod=1e9+7;
    while(t--)
    {
        LL n,m;
        cin>>n>>m;
        LL ans=qpow(2,n-1,mod);
        cout<<((ans%mod)*(m%mod))%mod<<endl;

    }


    return 0;
}
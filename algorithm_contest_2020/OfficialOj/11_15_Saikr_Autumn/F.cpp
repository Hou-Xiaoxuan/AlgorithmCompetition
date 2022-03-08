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


int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif

    LL ans[31],mod=1e9+7;
    ans[1]=1;
    for(int i=2;i<=30;i++)
    {
        ans[i]=(ans[i-1]%mod*((ans[i-1]+5)%mod))%mod;
    }
    LL cnt=0;
    for(int i=1;i<=30;i++) cnt+=ans[i];
    cout<<cnt%mod<<endl;
    return 0;
}

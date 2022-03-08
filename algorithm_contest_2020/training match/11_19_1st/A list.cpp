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

    LL n=1000;
    vector<LL> a(n+5);
    for(int i=1;i<=n;i++) a[i]=inf;
    a[1]=0;
    for(int i=1;i<=n;i+=2)
    {
        if(a[i]==inf) continue;
        for(LL j=1;j<=50;j++)
        {
            if((1<<j)-i<=n) a[(1<<j)-i]=min(a[(1<<j)-i],a[i]+1);
        }
    }
    for(int i=1;i<=n;i+=2)
    {
        cout<<i<<" "<<bitset<10>(i)<<' ';
        cout<<a[i]<<endl;
    }
    return 0;
}

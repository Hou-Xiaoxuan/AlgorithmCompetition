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

// 数量不同，结果必然不同
// tm没说要不要取模，模多少啊，高精度？？
// 10怎么回事244呢?好吧，打表发现存在很多重复的
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif

    int cnt[]={0,0,1,5,14,32,60,97,141,190};
    LL n;
    while(cin>>n)
    {
        LL ans=0;
        if(n<=3)
        {
            if(n==1) cout<<4<<endl;
            else if(n==2) cout<<10<<endl;
            else cout<<17<<endl;
        }
        else
        {
            LL a=n-1,b=n-2,c=n-3;
            ans+=4;
            ans+=a*6;
            ans+=a*b*2;
            ans+=a*b*c/6;
            cout<<ans<<endl;
        }
    }
    return 0;
}

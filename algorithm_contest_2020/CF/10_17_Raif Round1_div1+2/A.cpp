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
    
    // 移动1s，转向2s
    int t;cin>>t;
    while(t--)
    {
        LL x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        LL a=abs(x1-x2);
        LL b=abs(y1-y2);
        if(a==0 or b==0) cout<<a+b<<endl;
        else cout<<a+b+2<<endl;
    }
    return 0;
}
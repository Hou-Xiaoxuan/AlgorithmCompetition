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
//²¹Ìâ£ºÃ¶¾Ùa+b
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_contest\\in.txt","r",stdin);  
    #endif
   
    int a,b,c,d;
    while(cin>>a>>b>>c>>d)
    {
        LL ans=0;
        for(int i=max(c+1,a+b);i<=b+c;i++){//i=x+y
            LL l=max(a,i-c);//the min x
            LL r=min(b,i-b);//the max of x
            ans+=max(r-l+1,LL(0))*(min(d,i-1)-c+1);
        }
        cout<<ans<<endl;


        
    }
    return 0;
}
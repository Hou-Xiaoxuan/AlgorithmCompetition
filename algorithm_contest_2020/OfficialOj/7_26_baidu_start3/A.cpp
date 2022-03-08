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
//你好
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        int b;
        double c;
        double ans=0.0;
        for(int i=1;i<=n;i++)
        {
            cin>>b>>c;
            double tmp=(1-c)/(b+(1-c));
            ans=max(ans,tmp);
        }
        cout<<fixed<<setprecision(5)<<ans<<endl;


    }
    return 0;
}
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
int a[]={0,60,62,65,67,70,75,80,85,90,95};
double c[]={0,1.0,1.7,2.0,2.3,2.7,3.0,3.3,3.7,4.0,4.3};
double sor[105];
double ans[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1.7,1.7,1.7,2,2,2.3,2.3,2.3,2.7,2.7,2.7,2.7,2.7,3,3,3,3,3,3.3,3.3,3.3,3.3,3.3,3.7,3.7,3.7,3.7,3.7,4,4,4,4,4,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.3,4.4,4.4,4.6,4.7,4.7,5,5,5,5.4,5.4,5.4,5.4,5.4,5.7,5.7,5.7,5.7,5.7,6,6,6,6,6,6.4,6.4,6.4,6.4,6.4,6.7,6.7,6.7,6.7,6.7,7,7,7,7,7,7.4,7.4,7.4,7.4,7.4,7.7,7.7,7.7,7.7,7.7,8,8,8,8,8,8.3,8.3,8.3,8.3,8.3,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.6,8.7,8.7,8.7,8.7,8.7,9.1,9.1,9.1,9.1,9.1,9.4,9.4,9.4,9.4,9.4,9.7,9.7,9.7,9.7,9.7,10.1,10.1,10.1,10.1,10.1,10.4,10.4,10.4,10.4,10.4,10.7,10.7,10.7,10.7,10.7,11.1,11.1,11.1,11.1,11.1,11.4,11.4,11.4,11.4,11.4,11.7,11.7,11.7,11.7,11.7,12,12,12,12,12,12.3,12.3,12.3,12.3,12.3,12.6,12.6,12.6,12.6,12.6,12.9,12.9,12.9,12.9,12.9,12.9,12.9,12.9,12.9,12.9,12.9,12.9,12.9,12.9,12.9,12.9,12.9,12.9,12.9,12.9,12.9,12.9,12.9,12.9,12.9,12.9,12.9,12.9,12.9,12.9,13.1,13.1,13.1,13.1,13.1,13.4,13.4,13.4,13.4,13.4,13.8,13.8,13.8,13.8,13.8,14.1,14.1,14.1,14.1,14.1,14.4,14.4,14.4,14.4,14.4,14.8,14.8,14.8,14.8,14.8,15.1,15.1,15.1,15.1,15.1,15.4,15.4,15.4,15.4,15.4,15.7,15.7,15.7,15.7,15.7,16,16,16,16,16,16.3,16.3,16.3,16.3,16.3,16.6,16.6,16.6,16.6,16.6,16.9,16.9,16.9,16.9,16.9,17.2,17.2,17.2,17.2,17.2,17.2,17.2,17.2,17.2,17.2,17.2,17.2,17.2,17.2,17.2,17.2,17.2,17.2,17.2,17.2,17.2};
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    int t;cin>>t;
    int x;
    while(t--)
    {
        cin>>x; 
        cout<<fixed<<setprecision(1)<<ans[x]<<endl;
    }
    return 0;
}
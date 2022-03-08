#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
// #include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include <iomanip>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;
typedef long double LD;
LD V(LD r,LD S)
{
    LD l=(S-pow(r,2)*M_PI)/(M_PI*r);
    return M_PI*pow(r,2)*sqrt(pow(l,2)-pow(r,2))/3;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #elif _LINUX
    freopen("/media/linxuan/储存/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("/media/linxuan/储存/CODE/algorithm_contest/out.txt","r",stdin);
    #endif
    
    LD S;
    while(cin>>S)
    {
        LD l=0;
        LD r=sqrt(S/(2*M_PI));
        const LD esp=1e-7;
        while(r-l>esp)
        {
            LD mid=(l+r)/2;
            LD midmid=(mid+r)/2;
            if(V(mid,S)<V(midmid,S)){
                l=mid;
            }
            else{
                r=midmid;
            }
        }
        LD R=V(l,S)>V(r,S)?l:r;
        LD h=sqrt( pow( S/(R*M_PI)-R,2 ) -pow(R,2) );
        cout<<fixed<<setprecision(2)<<V(R,S)<<endl<<h<<endl<<R<<endl;
    }
    return 0;
}

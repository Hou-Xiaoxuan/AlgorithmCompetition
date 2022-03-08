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
typedef long double LD;
const int inf=0x3f3f3f3f;
// 经过证明以后，发现为凸性函数，三分求解
LD H,h,D;
LD f(LD R)
{
    // 注意分段函数
    if(R>(H-h)*D/H)
        return D-R+H-(D*(H-h)/R);
    else 
        return R*h/(H-h);
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
    
    int t;
    cin>>t;
    while(t--)
    {
        cin>>H>>h>>D;
        LD left=0,right=D;
        const LD esp=1e-3;
        while(right-left>esp)
        {
            LD mid=(left+right)/2;
            LD midmid=(mid+right)/2;
            if(f(mid)>f(midmid))
                right=midmid;
            else 
                left=mid;
        }
        cout<<fixed<<setprecision(3)<<max(f(left),f(right))<<endl;
    }
    return 0;
}

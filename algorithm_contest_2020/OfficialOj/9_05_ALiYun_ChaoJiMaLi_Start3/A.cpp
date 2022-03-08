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

long long gcd(long long a,long long b){
    return b?gcd(b,a%b):a;
}
long long greatestcommonmultiple(long long a, long long b)
{
    if((b&1)==1){
        return b*(b-1)*(b-2);
    }
    if(b-a==2)
    {
        long long gcd1,gcd2;
        gcd1=gcd(b,b-2);
        long long tmp=b*(b-2)/gcd1;
        gcd2=gcd(tmp,b-1);
        long long ans1=tmp*(b-1)/gcd2;
        return ans1;
    }
    if(b%3==0) return (b-1)*(b-2)*(b-3);
    else return b*(b-1)*(b-3);
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    cout<<greatestcommonmultiple(6,8);
    return 0;
}
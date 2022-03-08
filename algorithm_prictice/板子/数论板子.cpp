#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define x first
#define y second 
using namespace std;
using LL=long long;
using ULL=unsigned long long;
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;

// 欧拉筛
void get_prime(vector<int> & prime,int upper_bound)// 传引用
{ 
    if(upper_bound < 2)return;
    vector<bool> Is_prime(upper_bound+1,true);
    for(int i = 2; i <= upper_bound; i++)
    {
        if(Is_prime[i])
            prime.push_back(i);
        for(int j = 0; j < prime.size() and i * prime[j] <= upper_bound; j++){
            Is_prime[ i*prime[j] ] = false;
            if(i % prime[j] == 0) break;// 保证了一个数只被筛一次。
        }
    }
}

// gcd：
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

// exgcd:
//  x1=y2; y1=x2-(a/b)*b*y2;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0){
        x=1,y=0;
        return a;
    }
    else{
        int d=exgcd(b,a%b,y,x);
        y=y-(a/b)*x;
        return d;
    }
}

// 求a关于m的乘法逆元
long long mod_inverse(long long a,long long m){
    long long x,y;
    if(exgcd(a,m,x,y)==1)//ax+my=1
        return (x%m+m)%m;
    return -1;//不存在
}

// 快速幂quick power 计算 a^b %m
LL qpow(LL a,LL b,LL m){
    LL ans=1;
    LL k=a;
    while(b){
        if(b&1)ans=ans*k%m;
        k=k*k%m;
        b>>=1;
    }
    return ans;
}

// 快速乘,
LL qmul(LL a,LL b,LL m){
    LL ans=0;
    LL k=a;
    LL f=1;//f是用来存负号的
    if(k<0){f=-1;k=-k;}
    if(b<0){f*=-1;b=-b;}
    while(b){
        if(b&1)
            ans=(ans+k)%m;
        k=(k+k)%m;
        b>>=1;
    }
    return ans*f;
}

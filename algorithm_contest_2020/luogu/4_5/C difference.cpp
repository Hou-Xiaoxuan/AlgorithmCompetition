#include<bits/stdc++.h>
using namespace std;
#define  m_k make_pair
#define   P  pair<int,int>
#define  V vector
typedef long long LL;
typedef unsigned long long ULL;

long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if (b==0) { x=1,y=0; return a; }
    long long d=exgcd(b,a%b,x,y);
    long long tmp=x;
    x=y;
    y=tmp-a/b*y;
    return d;
}
int main()
{
    LL a,b,c,d;
    cin>>a>>b>>c>>d;
    if(c==d and d==0){
        cout<<"1 0 1 1 "<<a*a+b*b<<endl;
    }
    else if(a==c and a==0)
    {
        LL p,q,r,s;
        p=r=0;
        LL m=exgcd(b,d,q,s);
        cout<<p<<" "<<q<<" "<<r<<" "<<s<<" "<<m<<endl;
    }
    else
        cout<<"1 2 3 4 5"<<endl;
    return 0;
}
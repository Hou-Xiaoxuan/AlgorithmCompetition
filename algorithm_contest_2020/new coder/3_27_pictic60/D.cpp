#include<bits/stdc++.h>
using namespace std;
#define make_pair m_k
#define pair<int,int>  P
typedef long long LL;
typedef unsigned long long ULL;
int gcd(int a,int b)
{

    if(b==0)

        return a;

    return 

        gcd(b,a%b);

}
/*
void solve(LL a,LL b,LL c,LL k)
{
    if(k==0){
        cout<<"0 0 0"<<endl;
        return;
    }
    if(a>b) swap(a,b);
    if(a>c) swap(a,c);
    if(b>c) swap(b,c);
    LL k1=b/a;
    LL k2=c/a;
    b%=a;
    c%=a;
    LL c1=k/a;//总数量
    k%=a;
    //特殊情况
    if(b==0)
    {
        if(c==0){
            cout<<c1<<" 0 0"<<endl;
            return;
        }
        else{
            cout<<c1-k2*(k/c)<<" "<<0<<" "<<k/c<<endl;
            return;
        }
    }
    if(c==0){
        cout<<c1-k2*(k/b)<<" "<<k/b<<" "<<0<<endl;
    }
    if(k==0){
        cout<<c1<<" 0 0"<<endl;
        return;
    }
    //求y，z
    if(b<c)
    {
        LL k3=c/b; c%=b;
        LL c2=k/b;//b和c的分数
        k%=b;
        LL c3= c==0?0:(k/c);//c的最少分数
        if(c==0){
            c3+=c2/k3;
        }
        else {
            LL ii=gcd(b,k3*b+c);
            c3+=c2/(b/ii);
        }
        cout<<c1-k1*(c2-c3*k3)-c3*k2<<" "<<c2-c3*k3<<" "<<c3<<endl;
        return;
    }
    else 
    {
        swap(b,c);
        LL k3=c/b; c%=b;
        LL c2=k/b;//b和c的分数
        k%=b;
        LL c3= c==0?0:(k/c);//c的最少分数
        if(c==0){
            c3+=c2/k3;
        }
        else {
            LL ii=gcd(b,k3*b+c);
            c3+=c2/(b/ii);
        }
        cout<<c1-c3*k1-k2*(c2-c3*k3)<<" "<<c3<<" "<<c2-c3*k3<<endl;
        return;
    }
}
*///有个神奇的东西叫做扩展欧几里得定理
int main()
{
    //freopen("D:\\code_contest\\in.txt","r",stdin);  
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    LL a,b,c,k;
    while(cin>>a>>b>>c>>k)
         solve(a,b,c,k);
    return 0;
}

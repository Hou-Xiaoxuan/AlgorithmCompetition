// #include<bits/stdc++.h>
#include<iostream>
#include<cmath>
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
    freopen("D:\\CODE\\algorithm_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_prictice\\in.txt","r",stdin); 
    #endif
    
    int a,b;
    while(cin>>a>>b)
    {
        if(a>b) swap(a,b);
        double p=(sqrt(5.0)+1)/2;
        if(a==floor((b-a)*p))
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<1<<endl;
        }
    }
    return 0;
}
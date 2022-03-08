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
char a[1025][1025];

void build(int n)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            a[i+n][j]=a[i][j]=='C'?'P':'C';
            a[i+n][j+n]=a[i][j+n]=a[i][j];
        }
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    a[1][1]='C';
    a[1][2]='C';
    a[2][2]='C';
    a[2][1]='P';
    for(int i=1;i<=9;i++)
        build(1<<i);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        for(int i=1;i<=(1<<n);i++)
        {
            for(int j=1;j<=(1<<n);j++)
                cout<<a[i][j];
            cout<<endl;
        }   
    }
    return 0;
}
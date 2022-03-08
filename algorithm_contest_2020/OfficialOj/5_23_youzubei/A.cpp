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

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_contest\\in.txt","r",stdin);  
    #endif
    char s[10];
    int n,m;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++) cin>>s;
        cin>>m;
        for(int i=1;i<=m;i++) cin>>s;
        if(n>m) cout<<"Cuber QQ"<<endl;
        else cout<<"Quber CC"<<endl;
    }
    return 0;
}
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
char s[int(1e5+50)];
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    while(cin>>(s+1))
    {
        int n=strlen((s+1));
        if(s[1]==s[3])
        {
            cout<<2<<endl;
            cout<<"R 2"<<endl;
            cout<<'R'<<' '<<2*n-3<<endl;
        }
        else
        {
            cout<<3<<endl;
            cout<<"L 2"<<endl;
            n++;
            cout<<"R 2"<<endl;
            cout<<'R'<<' '<<2*n-3<<endl;
        }
    }

    return 0;
}
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
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int cnt=0;
    for(int a=1;a<=300;a++)
        for(int b=1;b<=300;b++)
            for(int c=1;c<=300;c++)
            {
                if(a+33*b+582/c==2982){
                    // cout<<a<<" "<<b<<" "<<c<<endl;
                    cnt++;
                }
            }

            cout<<cnt<<endl;
    return 0;
}

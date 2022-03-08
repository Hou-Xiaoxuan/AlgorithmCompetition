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
    
    int n,pos,l,r;
    while(cin>>n>>pos>>l>>r)
    {
        if(l==1 and r==n)
            cout<<0<<endl;
        else if(l==1)
            cout<<abs(r-pos)+1<<endl;
        else if(r==n)
            cout<<abs(pos-l)+1<<endl;
        else
        {
            if(pos<=l)
                cout<<abs(l-pos)+abs(r-l)+2<<endl;
            else if(pos>=r)
                cout<<abs(pos-r)+abs(r-l)+2<<endl;
            else
            {
                if(abs(pos-l)<abs(r-pos))
                    cout<<abs(pos-l)+abs(r-l)+2<<endl;
                else
                    cout<<abs(r-pos)+abs(r-l)+2<<endl;      
            }          
        }
        
    }
    return 0;
}
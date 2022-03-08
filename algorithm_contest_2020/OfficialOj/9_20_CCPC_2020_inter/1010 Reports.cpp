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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int x,y;
        bool flag=true;
        cin>>x;
        for(int i=2;i<=n;i++){
            cin>>y;
            if(y==x)
                flag=false;
            x=y;
        }
        if(flag==false) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
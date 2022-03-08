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
    #ifdef _DBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);
    #endif
    int n;while(cin>>n)
    {
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];

        int l,r;
        int cnt=0;
        for(int i=n;i>=1;i--)
        {
            if(a[i]!=i)
            {
                cnt++;
                int tmp=i-1;
                while(a[tmp]==a[tmp+1]+1) tmp--;
                l=tmp+1,r=i;
                i=tmp+1;
            }
        }
        if(cnt==1)
            cout<<l<<" "<<r<<endl;
        else cout<<"0 0"<<endl;
    }
    
   
    return 0;
}
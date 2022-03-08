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
    
    int t; cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int cnt1=0;
        vector<int> a(n+1);
        int l=-1,r=-1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            cnt1+=a[i];
            if(a[i]==1){
                if(l==-1) l=i;
                r=i;
            }
        }
        cout<<r-l+1-cnt1<<endl;

    }
    return 0;
}
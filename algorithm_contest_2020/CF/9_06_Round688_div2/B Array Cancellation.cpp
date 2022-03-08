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
    
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int>a(n+2);
        for(int i=1;i<=n;i++) cin>>a[i];

        int b,s=b=0;//a[b]<0 and a[s]>0
        while(a[++b]<=0);
        
        // while(1) //TLE
        // {   
        //     s=b+1;
        //     while(a[s]>=0 and s<=n) s++;
        //     if(s>n) break;
        //     int tmp=min(a[b],-a[s]);
        //     a[b]-=tmp; a[s]+=tmp;
        //     while(a[b]<=0) b++;
        // }
        while(1)
        {   
            while(a[s]>=0 and s<=n or s<b) s++;
            if(s>n) break;
            int tmp=min(a[b],-a[s]);
            a[b]-=tmp; a[s]+=tmp;
            while(a[b]<=0) b++;
        }

        long long ans=0;
        for(int i=1;i<=n;i++) if(a[i]>0) ans+=a[i];
        cout<<ans<<endl;
    }
   
    return 0;
}
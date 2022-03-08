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
// 只有我们组没有过的以到数学签到题%%%%%
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
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        bool flag=true;
        for(int i=2;i<=n;i++)
        {
            if(a[i]<a[i-1]){
                flag=false;
                break;
            }
        }
        if(a[1]!=0 or a[n]!=n-1) flag=false;
        if(flag==false){
            cout<<0<<endl;
            continue;
        }
        LL ans=1,cnt=0,mod=1e9+7;
        for(int i=2;i<=n;i++)
        {
            if(a[i]>a[i-1]){
                ans=ans*LL(2)%mod;
                cnt+=a[i]-a[i-1]-1;
            }
            else{
                ans*=(cnt--);
                ans%=mod;
            }
        }

        cout<<ans%mod<<endl;
    }
    return 0;
}
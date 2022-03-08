#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        if(n==1) cout<<1<<endl;
        else if(n==2) cout<<2<<endl;
        else if(n&1)
            cout<<LL(n)*LL(n-1)*LL(n-2)<<endl;
        else{
            LL ans=0;
            ans=max(ans,LL(n)*LL(n-1)*LL(n-2)/2);
            ans=max(ans,LL(n)*LL(n-1));
            ans=max(ans,LL(n-1)*LL(n-2)*LL(n-3));
           if(n%3) ans=max(ans,LL(n)*LL(n-1)*LL(n-3));
            cout<<ans<<endl;
        }
    }



    return 0;
}
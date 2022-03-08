#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    
    LL n,a,b;
    while(cin>>n>>a>>b)
    {
        LL cnt=n/(a+b);
        LL ans=cnt*a;
        cnt=n%(a+b);
        ans+=cnt>a?a:cnt;
        cout<<ans<<endl;
    }
    return 0;
}
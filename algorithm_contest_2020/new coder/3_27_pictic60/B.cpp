#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=998244353;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vector< pair<LL,LL> > a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second;
    LL ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            ans+=(LL(n-2)*(abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second)))%mod;
    cout<<ans%mod<<endl;
    return 0;
}
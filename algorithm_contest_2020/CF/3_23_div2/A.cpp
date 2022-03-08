#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        long long n,m;
        cin>>n>>m;
        if((n&1)!=(m&1)) cout<<"NO"<<endl;
        else if(n<LL(m)*m) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

    return 0;
}

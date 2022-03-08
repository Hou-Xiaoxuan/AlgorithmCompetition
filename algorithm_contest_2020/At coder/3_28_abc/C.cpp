#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
#define k_p make_pair


int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        vector<int> a(n+1);
        for(int i=1;i<=k;i++)
            cin>>a[i];
        int ans=0;
        for(int i=2;i<=k;i++)
            ans=max(ans,a[i]-a[i-1]);
        ans=max(a[1]+n-a[k],ans);
        cout<<n-ans<<endl;
    }
    
    return 0;
}

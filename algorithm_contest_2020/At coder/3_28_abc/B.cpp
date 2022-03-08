#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
#define k_p make_pair


int main()
{
    int x;
    while(cin>>x)
    {
        LL ans=0;
        ans+=(x/500)*1000;
        x%=500;
        ans+=(x/5)*5;
        cout<<ans<<endl;


    }
    
    return 0;
}

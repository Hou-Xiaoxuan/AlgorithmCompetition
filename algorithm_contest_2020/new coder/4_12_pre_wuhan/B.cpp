#include<bits/stdc++.h>
using namespace std;
#define  m_k make_pair
#define   P  pair<int,int>
#define  V vector
typedef long long LL;
typedef unsigned long long ULL;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int a[21]={0},b[21]={0};
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(x>=0) a[x]++;
        else b[-x]++;
    }
    LL ans=0;
    for(int i=1;i<=20;i++)
        ans+=LL(a[i])*LL(b[i]);
    if(a[0]) ans+=LL(a[0]-1)*a[0]/2;
    cout<<ans<<endl;

    return 0;
}
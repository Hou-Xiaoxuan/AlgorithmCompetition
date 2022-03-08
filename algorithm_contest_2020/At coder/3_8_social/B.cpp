#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N],b[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n1,n2,m;
    while(cin>>n1>>n2>>m)
    {
        int ia=N,ib=N;
        for(int i=1;i<=n1;i++){
            cin>>a[i];
            ia=min(ia,a[i]);
        }
        for(int i=1;i<=n2;i++){
            cin>>b[i];
            ib=min(ib,b[i]);
        }
        int ans=ia+ib,x,y,z;
        for(int i=1;i<=m;i++){
            cin>>x>>y>>z;
            ans=min(ans,a[x]+b[y]-z);
        }

        cout<<ans<<endl;

    }

    return 0;
}
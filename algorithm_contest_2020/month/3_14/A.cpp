#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;cin>>T;
    while(T--)
    {
        int n,m;    cin>>n>>m;
        vector<int>  f(m+1);
        int inf=0x3f3f3f3f;
        for(int i=1;i<=m;i++) f[i]=-inf;
        for(int i=1;i<=n;i++){
            int v,w;cin>>v>>w;
            for(int j=m;j>=v;j--)
                f[j]=max(f[j],f[j-v]-w);
        }
        if(f[m]==-inf)
            cout<<-1<<endl;
        else cout<<-f[m]<<endl;
    }



    return 0;
}
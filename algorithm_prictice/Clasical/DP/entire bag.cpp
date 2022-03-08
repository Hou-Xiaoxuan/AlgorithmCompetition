#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
const int N=1005;
int f[N],v[N],w[N];
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        memset(f,0,sizeof(0));
        for(int i=1;i<=n;i++)
            cin>>w[i]>>v[i];
        for(int i=1;i<=n;i++)
            for(int j=w[i];j<=m;j++)
                f[j]=max(f[j],f[j-w[i]]+v[i]);
        cout<<f[m]<<endl;
    }
    return 0;
}
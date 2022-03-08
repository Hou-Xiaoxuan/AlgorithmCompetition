#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
const int N=1005;
int f[N],v[N],w[N],c[N];
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
            cin>>w[i]>>v[i]>>c[i];
            //AC
        for(int i=1;i<=n;i++)    
           for(int j=m;j>=w[i];j--)//倒序
                for(int k=1;k<=c[i] and w[i]*k<=j;k++)//这里时将一件物品看成了多件
                    f[j]=max(f[j],f[j-k*w[i]]+v[i]*k);
            
           /*WA //实际上无法控制数量了。
        for(int i=1;i<=n;i++)
            for(int k=1;k<=c[i];k++)
                for(int j=m;j>=k*w[i];j--)
                     f[j]=max(f[j],f[j-k*w[i]]+v[i]*k);
            */
        cout<<f[m]<<endl;
    }
    return 0;
}
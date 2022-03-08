#include<bits/stdc++.h>
using namespace std;
const int N=100000;

/*WA,完全不明白为什么，不就是01背包吗？为什么二维就不行？
const int inf=0x3f3f3f3f;
int f[100][N*2+5];//Si is i, the max of Fi
int main()
{
    int n;cin>>n;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=N*2;j++)
            f[i][j]=-inf;
    for(int i=0;i<=n;i++) f[i][N]=0;
    
    for(int i=1;i<=n;i++)
    {
        int x,y;cin>>x>>y;
        if(x<0 and y<0) continue;
        for(int j=1;j<=N*2;j++)
            if(j-x>=0 and f[i-1][j-x]!=-inf)
                f[i][j]=max(f[i-1][j-x]+y,f[i-1][j]);
    }
    int ans=-1;
    for(int k=1;k<=n;k++)
    for(int i=N;i<=N*2;i++) 
        if(f[k][i]>=0 and f[k][i]!=-inf){
            cout<<f[k][i]<<" "<<i-N<<endl;
            ans=max(ans,f[k][i]+i-N);
            }
    cout<<ans<<endl;
    return 0;
}
*/
/*AC*/
int f[N*2+1005];
int main()
{
    int n;cin>>n;
    memset(f,-0x3f,sizeof(f));
    const int inf=-f[0];
    f[N]=0;
    for(int i=1;i<=n;i++)
    {
        int x,y;cin>>x>>y;
        if(x<0 and y<0) continue;
        
        if(x>0){
            for(int j=N*2;j>=x;j--){
                if(f[j-x]>-inf)
                f[j]=max(f[j],f[j-x]+y);
            }
        }
        else{
            for(int j=0;j<=N*2+x;j++){
                if(f[j-x]>-inf)
                f[j]=max(f[j],f[j-x]+y);
            }
        }
    }
    int ans=-1;
    for(int j=N;j<=N*2;j++)
        if(f[j]>=0)
           ans=max(ans,f[j]+j-N);
    cout<<ans<<endl;

    return 0;
}
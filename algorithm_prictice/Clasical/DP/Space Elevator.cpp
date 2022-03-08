#include<bits/stdc++.h>
using namespace std;
int dp[40001];
struct num{
    int h=0,v=0,c=0;
    bool operator <(num a){
        return v<a.v;
    }
}nod[401];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>nod[i].h>>nod[i].v>>nod[i].c;
    sort(nod+1,nod+n+1);
    memset(dp,0,sizeof(dp));
    /*AC题解
    int ans=0;  dp[0]=true;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=nod[i].c;j++)//大概是空间优化过的多重背包
            for(int k=nod[i].v;k>=nod[i].h;k--)//完全不知道为什么是对的：按照多重背包的顺序计算每个塔高的可能性
               if(dp[k-nod[i].h]){
                dp[k]=true;
                ans=max(ans,k);
               } 
    cout<<ans<<endl;
    */
   /*ac*/ //高不清楚需不需要找最大值，就全部找
   for(int i=1;i<=n;i++){
        for(int j=nod[i].v;j>=nod[i].h;j--)
            for(int k=0;k<=nod[i].c and k*nod[i].h<=j;k++)
                dp[j]=max(dp[j],dp[j-k*nod[i].h]+k*nod[i].h);
   }
   int ans=-1;
   for(int i=1;i<=nod[n].v;i++)
        ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}
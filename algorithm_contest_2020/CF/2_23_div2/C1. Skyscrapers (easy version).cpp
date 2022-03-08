// The twe besides' buildings even not next to this can't be higher than this,
//whitch mean the aray has an biggest and lower from this one.
// What a pity that I complicate the question
#include<bits/stdc++.h>
//ฒน
using namespace std;
typedef long long LL;
int a[1005],m[1005],temp[1005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[0]=a[n+1]=0;
    LL ans=0;
    for(int j=1;j<=n;j++)
    {  
        LL cnt=0;
        memset(temp,0,sizeof(temp));
        temp[j]=a[j];
        for(int i=j-1;i>=1;i--){
            temp[i]=min(temp[i+1],a[i]);
        }
        for(int i=j+1;i<=n;i++){
            temp[i]=min(temp[i-1],a[i]);
        }
        for(int i=1;i<=n;i++)
             cnt+=temp[i];
        if(cnt>ans)
            memcpy(m,temp,sizeof(m)),ans=cnt;
    }
    for(int i=1;i<=n;i++)
        cout<<m[i]<<" ";
    cout<<endl;
    return 0;
}
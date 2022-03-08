//#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long LL;
int main()
{
    int n;cin>>n;
    LL cnt[30]={0};
    LL a[30];
    for(int i=0;i<=27;i++)
        a[i]=(1<<i);
    int x=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        int t=27;
        for(;x;)
        {
            if(a[t]<=x){
                cnt[t]++;
                x-=a[t];
            }
            t--;
        }
    }
    LL ans=0;
    for(int i=0;i<=27;i++)
        ans+=cnt[i]*cnt[i]*a[i];
    cout<<ans<<endl;
    return 0;
}
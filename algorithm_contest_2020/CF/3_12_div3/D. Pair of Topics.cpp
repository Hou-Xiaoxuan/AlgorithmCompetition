#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int>a(n+1),ia,ib;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            a[i]-=x;
            if(a[i]>0) ia.push_back(a[i]);
            else ib.push_back(a[i]);
        }
        sort(ia.begin(),ia.end());
        long long ans=0;
        ans+=(LL(ia.size())*LL((ia.size()-1))/2);//必须强制类型转换，不然爆精度
        for(int i=0;i<ib.size();i++){
            int t=upper_bound(ia.begin(),ia.end(),-ib[i])-ia.begin();
            //cout<<t<<" ";
            ans+=ia.size()-t;
        }
        cout<<ans<<endl;
    }
   return 0;
}
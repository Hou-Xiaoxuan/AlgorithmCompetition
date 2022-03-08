#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int> a(n+1);
        vector<int> cnt(n+1);
        bool flag=false;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(cnt[a[i]]>1 or (a[i]!=a[i-1] and cnt[a[i]]>0) )
                flag=true;
            cnt[a[i]]++;
        } 
        if(flag)
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
    }
    return 0;
}
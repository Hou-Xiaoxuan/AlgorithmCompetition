#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;
    while(t--)
    {
        string s; cin>>s;
        vector<int> a;
        a.push_back(0);
        for(int i=0;i<s.size();i++){
            if(s[i]=='R') a.push_back(i+1);
        }
        a.push_back(s.size()+1);
        int ans=0;
        for(int i=1;i<a.size();i++)
            ans=max(a[i]-a[i-1],ans);
        cout<<ans<<endl;
    }
    return 0;
}
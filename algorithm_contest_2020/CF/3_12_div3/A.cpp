#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int cnt=0,tmp;
        for(int i=1;i<=n;i++){
            cin>>tmp;
            if(tmp&1) cnt++;
        }
        //cout<<cnt<<" ";
        if(cnt==n or cnt==0)
            cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
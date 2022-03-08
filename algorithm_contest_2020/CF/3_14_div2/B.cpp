#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;  cin>>n;
        vector<int>a(n+1);
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a.begin(),a.end());
        int cnt=unique(a.begin()+1,a.end())-a.begin();

        cout<<cnt-1<<endl;

    }


    return 0;
}
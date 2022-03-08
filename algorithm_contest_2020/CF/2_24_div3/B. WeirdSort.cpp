#include<bits/stdc++.h>
using namespace std;
//AC
int main()
{
    int T;cin>>T;
    while(T--)
    {
        int n,m,t;
        cin>>n>>m;
        vector<int> a(n+1);
        vector<bool> vis(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=m;i++) {cin>>t; vis[t]=true;}
        bool flag=true;
        for(int i=1;i<=n and flag;i++)
            for(int j=1;j<=n-i and flag;j++)
                if(a[j]>a[j+1]){
                    if(vis[j])
                        swap(a[j],a[j+1]);
                    else
                        flag=false;                     
                }
    if(flag)
        cout<<"YES"<<endl;   
    else 
        cout<<"NO"<<endl;             
    }

    return 0;
}
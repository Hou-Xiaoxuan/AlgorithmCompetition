#include<bits/stdc++.h>
using namespace std;
int main()
{

    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<vector<int> > a(n+1);
        vector<bool> vis(n+1);
        for(int i=1;i<=n;i++){
            int m;cin>>m;
            for(int j=1;j<=m;j++){
                int x;cin>>x;
                a[i].push_back(x);
            }
            sort(a[i].begin(),a[i].end());
        }
        queue<int> que;
        for(int i=1;i<=n;i++)
        {
            int cnt=0;
            for(int j=0;j<a[i].size();j++){
                if(vis[a[i][j]]==false){vis[a[i][j]]=true;break;}
                else cnt++;
            }
            if(cnt==a[i].size()) que.push(i);
        }
        vector<int> la;
        for(int i=1;i<=n;i++)
            if(vis[i]==false)
                la.push_back(i);
       if(!que.empty() and !la.empty()){
           cout<<"IMPROVE"<<endl;
           cout<<que.front()<<" "<<la[0]<<endl;
       }
       else cout<<"OPTIMAL"<<endl;
    
    }
    return 0;
}
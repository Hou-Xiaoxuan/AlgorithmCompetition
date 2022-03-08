#include<bits/stdc++.h>
using namespace std;


int main()
{
    bool vis[105]={false};
    int a[4][4];
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++) cin>>a[i][j];
    int n; cin>>n;
    int x;
    for(int i=1;i<=n;i++){
        cin>>x; vis[x]=true;
    }
    bool flag=false;
    for(int i=1;i<=3;i++){
        if(vis[a[i][1]] and vis[a[i][2]] and vis[a[i][3]])
            flag=true;
        else if(vis[a[1][i]] and vis[a[2][i]] and vis[a[3][i]])
            flag=true;
    }
    if(vis[a[1][1]] and vis[a[2][2]] and vis[a[3][3]])
        flag=true;
    if(vis[a[1][3]] and vis[a[2][2]] and vis[a[3][1]])
        flag=true;
    if(flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
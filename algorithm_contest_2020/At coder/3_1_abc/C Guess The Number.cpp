#include<bits/stdc++.h>
using namespace std;
//只要满足条件就行了，如果没有条件，最高位可以初始化为1
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        vector<int> a(n+1),vis(n+1);    
        for(int i=1;i<=n;i++) a[i]=0,vis[i]=false;
        int x,y;
        bool flag=true;
        if(n>1) a[1]=1;//为了这一句，折腾了一个小时
        for(int i=1;i<=m;i++)
        {
            cin>>x>>y;
            if(vis[x]==true and a[x]!=y)
                flag=false;
            else{
                a[x]=y; 
                vis[x]=true;
            }
        }
        if(n!=1 and a[1]==0) flag=false;
        if(flag)
            for(int i=1;i<=n;i++)
                cout<<a[i];
        else
            cout<<-1;       
        cout<<endl;
    }
    return 0;
}

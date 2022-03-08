#include<bits/stdc++.h>
using namespace std;
vector<int> du(1005),pa(1005);//in(1005),out(1005);
int search(int x)
{
    return pa[x]==x?x:pa[x]=search(pa[x]);
}
bool combin(int x,int y)
{
    int a=search(x);
    int b=search(y);
    if(a==b) return false;
    pa[a]=b;
    return true;
}
int main()
{
    int n,m;
    while(1)
    {
        cin>>n; if(n==0) break;
        for(int i=1;i<=n;i++) du[i]=0,pa[i]=i;//in[i]=out[i]=0;
        cin>>m;
        int u,v,sum=n;;
        for(int i=1;i<=m;i++){
            cin>>u>>v;
            du[v]++,du[u]++;
            if(combin(u,v)==true) sum--;
        }
        int cnt[2]={0};
        for(int i=1;i<=n;i++)
            cnt[du[i]&1]++;
        if(cnt[1]==0 and sum==1)
            cout<<1<<endl;
        else
            cout<<0<<endl;            
    }
    system("pause");
    return 0;
}
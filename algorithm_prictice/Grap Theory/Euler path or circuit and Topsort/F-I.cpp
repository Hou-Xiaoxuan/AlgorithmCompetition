#include<bits/stdc++.h>
using namespace std;

const int N=2000005;
int pa[N],cnt[N],du[N],n,m;
void initia(){
    for(int i=1;i<=n;i++)
        pa[i]=i,cnt[i]=0,du[i]=0;
}
int search(int x){
    return pa[x]==x?x:pa[x]=search(pa[x]);
}
void unio(int x,int y){
   int a=search(x),b=search(y);
   if(a!=b) pa[a]=b;
}
int main()
{
    freopen("D:\\code\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    

    while( cin>>n>>m)
    {
        initia();
        int u,v;
        for(int i=1;i<=m;i++){
            cin>>u>>v;
            du[u]++,du[v]++;
            unio(u,v);
        }
        for(int i=1;i<=n;i++)
            if(du[i]&1)
                cnt[search(i)]++;
        int sum=0;
        for(int i=1;i<=n;i++)
            if(pa[i]==i and du[i])//代表一个“集团”
                sum+= cnt[i]==0?1:cnt[i]/2;//cnt==0 代表 回路，否则为路径
        cout<<sum<<endl;
    }
    return 0;
}
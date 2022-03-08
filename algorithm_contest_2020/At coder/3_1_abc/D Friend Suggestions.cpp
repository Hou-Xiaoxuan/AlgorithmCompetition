#include<bits/stdc++.h>
//补题
using namespace std;
const int N=1e5+5;
int pa[N],cnt[N],fr[N];
 int n,m,k;
 //我这个傻逼，search函数少写了一个值:: pa[x]==x?x:search(x);
int search(int x){
    //if(pa[x]!=pa[pa[x]]) pa[x]=search(pa[x]);//*这一句速度竟然能差 50倍？？
    return pa[x]==x?pa[x]:pa[x]=search(pa[x]);
    
}
inline void uion(int x,int y){//*不止那一句，还有这里，如果写在函数里里面的话，就错了
    int a=search(x);
    int b=search(y);
    if(a!=b){
        pa[a]=b;
        cnt[b]+=cnt[a];   
     }
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n>>m>>k)
    { 
        for(int i=1;i<=n;i++){
            pa[i]=i; cnt[i]=1; fr[i]=0;
        }
        int x,y;
        while(m--) {
            cin>>x>>y;
            fr[x]++;fr[y]++;
            uion(x,y);
        }
        for(int i=1;i<=n;i++){
            cnt[i]=cnt[search(i)];
        }
        while(k--)
        {
            cin>>x>>y;
            int a=search(x);
            int b=search(y);
            if(a==b){
                cnt[x]--; cnt[y]--;
            }
        }
        for(int i=1;i<=n;i++)
            cout<<cnt[i]-fr[i]-1<<' ';
        cout<<endl;
    
    }

    return 0;
}
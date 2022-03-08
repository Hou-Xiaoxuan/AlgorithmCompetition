/*https://ac.nowcoder.com/acm/problem/25090*/
//多重拆分只要在多次重复求和就可以了
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
struct node{
    LL a=0;
    LL b=0;
    LL c=0;
    LL sum(){return (a+b+c)%mod;}
};
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m; 
        vector<node> t(n+1);
        int type,pos;
        for(int i=1;i<=m;i++)
        {
            cin>>type>>pos;
            if(type==1) t[pos].a++;
            else if(type==2) t[pos].b++;
            else t[pos].c++,t[pos+1].c++;
        }

        for(int i=1;i<=n;i++) t[i].a=(t[i].a+t[i-1].a)%mod;
        for(int i=1;i<=n;i++) t[i].b=(t[i].b+t[i-1].b)%mod;
        for(int i=1;i<=n;i++) t[i].b=(t[i].b+t[i-1].b)%mod;
        for(int i=1;i<=n;i++) t[i].c=(t[i].c+t[i-1].c)%mod;
        for(int i=1;i<=n;i++) t[i].c=(t[i].c+t[i-1].c)%mod;
        for(int i=1;i<=n;i++) t[i].c=(t[i].c+t[i-1].c)%mod;
        
        for(int i=1;i<=n;i++)
            cout<<t[i].sum()<<" ";
        cout<<endl;
    }
    return 0;
}

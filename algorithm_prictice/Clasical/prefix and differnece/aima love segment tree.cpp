//https://ac.nowcoder.com/acm/problem/25737?&headNav=acm
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
//前面影响后面的话，就倒着来；如线段树作业里的贴广告
const LL mod=1e9+7;
struct node{
    int l=0;
    int r=0;
    int type=0;
};
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<node> ope(m+1);
    vector<LL> a(n+2),b(n+2);//prefix and suffix
    for(int i=1;i<=m;i++)
    {
        cin>>ope[i].type>>ope[i].l>>ope[i].r;
        if(ope[i].type==1)
            a[ope[i].l]++,a[ope[i].r+1]--;
        else
            b[ope[i].r]++,b[ope[i].l-1]--;
    }
    for(int i=m;i>=1;i--)
    {
        b[i]=(b[i]+b[i+1])%mod;
        if(ope[i].type==1)
            (a[ope[i].l]+=b[i])%=mod,(a[ope[i].r+1]-=b[i])%=mod;
        else 
            (b[ope[i].r]+=b[i])%=mod,(b[ope[i].l-1]-=b[i])%=mod;
    }
    for(int i=1;i<=n;i++)
        a[i]=((a[i]+a[i-1])%mod+mod)%mod;//这里的数可能会大于小于0，所以转化成正数
    for(int i=1;i<=n;i++) cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}
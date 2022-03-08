#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;
// 直接dfs tm竟然能过
map<LL,LL> ma;
LL a,b,c,d;
LL dfs(LL n)
{
    if(ma.count(n)!=0) return ma[n];
    LL ans= double(n)*d>3e18?1e18:n*d;
    
    if(n%2==0) ans=min(ans,dfs(n/2)+a);
    else{
        ans=min(ans,dfs(n/2)+a+d);
        ans=min(ans,dfs(n/2+1)+a+d);
    }
    if(n%3==0) ans=min(ans,dfs(n/3)+b);
    else
    {
        LL l=n/3,r=l+1;
        ans=min(ans,dfs(l)+b+(n-l*3)*d);
        ans=min(ans,dfs(r)+b+(r*3-n)*d);
    }
    if(n%5==0) ans=min(ans,dfs(n/5)+c);
    else
    {
        LL l=n/5,r=l+1;
        ans=min(ans,dfs(l)+c+(n-l*5)*d);
        ans=min(ans,dfs(r)+c+(r*5-n)*d);
    }
    
    ma[n]=ans;
    return ans;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    int t;cin>>t;
    while(t--)
    {
        ma.clear();
        LL n;
        cin>>n>>a>>b>>c>>d;
        ma[1]=d;
        ma[0]=0;
        cout<<dfs(n)<<endl;
    }
    return 0;
}
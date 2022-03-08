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
//区间修改，单点查询（差分）
const int N=1e6;
int c[N];//差分数组
void add(int p,int n,int x){//给差分数组的p位增加x
    while(p<=n){
        c[p]+=x;
        p+=p&(-p);
    }
}
void add_range(int l,int r,int n,int x){//给原数组区间l~r增加x
    add(l,n,x); add(r+1,n,-x);
}
int ask(int p){//得到原数组的p位
    int ans=0;
    while(p>0){
        ans+=c[p];
        p-= p&(-p);
    }
    return ans;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_prictice\\in.txt","r",stdin);  
    #endif
    
    return 0;
}

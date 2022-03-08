//https://www.luogu.com.cn/problem/P3374

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
const int N=5e6+5;
//区间查询，单点修改
int a[N],c[N];
int lowbit(int x){
    return x&(-x);
}
void update(int x,int n,int value){//x位增加value
    a[x]+=value;
    while(x<=n){
        c[x]+=value;
        x+=lowbit(x);
    }
}
int get_sum(int x){//求出前x位的和
    int ans=0;
    while(x>0){
        ans+=c[x];
        x-=lowbit(x);
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
    
    int n,m;
    cin>>n>>m;
    memset(a,0,sizeof(int)*(n+5));
    memset(c,0,sizeof(int)*(n+5));
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        update(i,n,x);
    }
    while(m--)
    {
        int x,y,v;
        cin>>x>>y>>v;
        if(x==1){
            update(y,n,v);
        }
        else{
            cout<<get_sum(v)-get_sum(y-1)<<endl;
        }
    }
    return 0;
}

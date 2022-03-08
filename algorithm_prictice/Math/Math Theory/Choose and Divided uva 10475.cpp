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
// 使用唯一分解定理求解
int primes[1500],cnt=0;
bool vis[10005];
int e[1500]={0};
void add_interger(int n,int d)//把n分解为素数乘积，d代表乘还是除
{
    for(int i=1;i<=cnt;i++)
    {
        while(n%primes[i]==0){
            n/=primes[i];
            e[i]+=d;
        }
        if(n==1) break;
    }
}
void add_factorial(int n,int d)//添加 n的阶乘
{
        for(int i=1;i<=n;i++) add_interger(i,d);
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_prictice\\in.txt","r",stdin); 
    #endif
    
    // 获得素数
    memset(vis,0,sizeof(0));
    for(int i=2;i<=10000;i++)
    {
        if(vis[i]==1) continue;
        else
        {
            for(int j=2*i;j<=10000;j+=i) vis[j]=1;
        }
    }
    for(int i=2;i<=10000;i++) if(vis[i]==0) primes[++cnt]=i;

    int p,q,r,s;
    while(cin>>p>>q>>r>>s)
    {
        memset(e,0,sizeof(e));
        add_factorial(p,1);
        add_factorial(q,-1);
        add_factorial(p-q,-1);
        add_factorial(r,-1);
        add_factorial(s,1);
        add_factorial(r-s,1);
        double ans=1.0;
        for(int i=1;i<=cnt;i++) ans*=pow(double(primes[i]),double(e[i]));
        cout<<fixed<<setprecision(5)<<ans<<endl;
        cout.unsetf(ios_base::fixed);//撤销fixed
    }

    return 0;
}
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
// 先手取完之后会变成变成链状
// 用递归去计算子游戏的sg值
// 题解：https://www.cnblogs.com/fht-litost/p/9292113.html
const int N=1005;
int sg[N];

int SG(int n,int m)//求n点的SG值
{
    if(sg[n]!=-1) return sg[n];
    if(n<m) return sg[n]=0;
    bool vis[N];//不能公用一个vis数组
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=n-m;i++)//枚举子状态
       vis[SG(i,m)^SG(n-m-i,m)]=1;
    for(int j=0;j<=n;j++)
        if(vis[j]==0){
            return sg[n]=j;
        }
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_prictice\\in.txt","r",stdin); 
    #endif
    
    int t; cin>>t;
    int cnt=0;
    while(cnt++<t)
    {
        int n,m;cin>>n>>m;
        if(n<m){
            cout<<"Case #"<<cnt<<": abcdxyzk"<<endl;
            continue;
        }

        memset(sg,-1,sizeof(sg));
        SG(n-m,m);
        if(sg[n-m]==0)//n-m并不保证大于0
            cout<<"Case #"<<cnt<<": aekdycoin"<<endl;
        else 
            cout<<"Case #"<<cnt<<": abcdxyzk"<<endl;
    }


    return 0;
}
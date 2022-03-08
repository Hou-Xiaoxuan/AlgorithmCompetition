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
const int N=5e5+5;
// 计算欧拉函数值 模板
int phi[N]={0};
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_prictice\\in.txt","r",stdin); 
    #endif
    phi[1]=1;
    for(int i=2;i<N;i++)
    {
        if(phi[i]!=0) continue;
        for(int j=i;j<N;j+=i){
            if(phi[j]==0) phi[j]=j;//公式开头的n
            phi[j]=phi[j]/i*(i-1);
        }
    }
    int n;
    while(cin>>n and n)
    {
        LL ans=0;
        for(int i=2;i<=n;i++) ans+=phi[i];
        ans*=2;
        ans++;
        cout<<ans<<endl;
    }
    return 0;
}
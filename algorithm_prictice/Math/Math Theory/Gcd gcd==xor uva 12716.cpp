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
// n^log(n*n)复杂夫实在太大了，超过了1e9，必须优化
// AC b=a-c这个规律真的不一定能找到啊
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
LL ans[int(3e7+5)]={0};
int main()
{
    // IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_prictice\\in.txt","r",stdin); 
    #endif

    const int N=3e7;
    for(int c=1;c<=N/2;c++)
    {
        // cout<<"debug"<<c<<endl;
        for(int a=c*2;a<=N;a+=c)
        {
            int b=a-c;
            if((a^b)==c)
                ans[a]++;        
        }
    }
    for(int i=2;i<=N;i++)ans[i]+=ans[i-1]; 
    int T;/*cin>>T;*/
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        int n;
        // cin>>n;
        scanf("%d",&n);
        printf("Case %d: %lld\n",t,ans[n]);
    }
    
    return 0;
}
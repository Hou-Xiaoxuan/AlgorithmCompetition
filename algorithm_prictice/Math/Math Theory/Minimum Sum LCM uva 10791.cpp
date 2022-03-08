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
pair<LL,LL> a[110]; //n最多有31个因数
// TLE,去掉 pow的调用
// TLE,将分解改成sqrt(n),我有预感，就是这个
// WA,没有处理 大于sqrt(n)的因数(最后n剩下一个质数)
// AC,虽然思路有了，但是小错误不断啊
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_prictice\\in.txt","r",stdin); 
    #endif
    
    
    int t=0;
    LL n;
    while(cin>>n and n!=0 and ++t)
    {
        if(n==1){
            cout<<"Case "<<t<<": "<<2<<endl;
            continue;
        }
        int cnt=0;
        LL m=sqrt(n);
        for(int i=2;i<=m and n>1;i++){
            if(n%i==0)
            {
                a[++cnt].first=i;
                a[cnt].second=1;
                while(n%i==0 and n>1) {
                    a[cnt].second*=i;
                    n/=i;
                }
            }
        }
        if(n>1) a[++cnt].second=n;
        LL ans=0;
        for(int i=1;i<=cnt;i++) ans+=a[i].second;

        if(cnt==1) ans++;
        cout<<"Case "<<t<<": "<<ans<<endl;
    }
    return 0;
}
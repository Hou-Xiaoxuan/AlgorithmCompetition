#include<bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define P pair<int,int>
#define x first
#define y second
typedef long long LL;
const int inf=0x3f3f3f3f;
// 打表代码
LL f(LL n)
{
    LL ans=1;
    LL mod=10;

    while(n%mod!=n){
        ans*=(n%mod);ans%=(n+1);
        mod*=10;
    }
    ans*=n;
    ans%=(n+1);
    return ans;
}

int main()
{
    #ifdef _DEBUG
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    int ans=-1;
    for(int i=1;i<=(1e6);i++)
    {
        int tmp=i;
        int cnt=1;
        while(tmp!=f(tmp)){
            tmp=f(tmp);
            cnt++;
        }
         ans=max(ans,cnt);
    }
    cout<<ans<<endl;

    return 0;
}
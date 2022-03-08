#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define x first
#define y second 
using namespace std;
using LL=long long;
using ULL=unsigned long long;
using LD=long double;
using P=pair<int,int>;
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;
/*
*每个地方能跳到哪个地方与上一个点无关，只与当前的数字有关。
*每个地方必须到达a[i]-1次，同时可以向外传递a[i]-1次，这a[i-1]次的位置固定
*你tm的读错题了！！
*/
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #endif
    
    int t=0; cin>>t;
    while(t--)
    {
        LL n;
        cin>>n;
        vector<LL> a(n+1),cnt(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];

        LL ans=0;
        a[0]=1;
        for(int i=1;i<=n;i++)
        {
            cnt[i]+=max(cnt[i-1]-a[i-1]+1,0ll);
            ans+=max(0ll,a[i]-cnt[i]-1);
            LL r=min(n,i+a[i]);
            LL l=i+2;
            for(LL k=l;k<=r;k++)
                cnt[k]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

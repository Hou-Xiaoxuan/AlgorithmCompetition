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
// size_t确实多过了两个……但是还有12个……原因是？
int main()
{
    IOS;
    #ifdef _DEBU
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #endif
    
    size_t m;
    string s;
    cin>>s;
    cin>>m;
    size_t d=0;
    for(auto ch:s)
        d=max(d,size_t(ch-'0'));
    if(s.size()==1)
    {  
        if(s[0]-'0'<=m) cout<<1<<endl;
        else cout<<0<<endl;
        return 0;
    }
    auto check=[](size_t n,string s,size_t m)->bool{
        long double tmp=0;
        for(auto ch:s){
            tmp*=n;//n进制
            tmp+=(ch-'0');
            if(tmp>m){
                return false;
            }
        }
        return tmp<=m;
    };
    size_t l=d+1,r=1e18+5;
    size_t ans=d;
    check(2,s,m);
    while(l<=r)
    {
        size_t mid=(l+r)>>1;
        if(check(mid,s,m)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans-d<<endl;
    return 0;
}

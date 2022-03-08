#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
const int inf=0x3f3f3f3f;
long double esp=1e-10;
 LL a,b,k;
bool check(long double n)
{
    // long double d1=a*log2(n);
    // long double d2=b*log2(ceil(log2(n)));
    // long double d3=log2(k);
    // if(fabs(d1+d2-d3)<=esp) return true;
    // else return d1+d1<d3;
    LD  tmp=pow(n,a);
    tmp*=pow(ceil(log2(n)),b);
    if(fabs(tmp-k)<=esp) return true;
    else return tmp<k;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin); 
    #endif
    
    int t;cin>>t;
    while(t--)
    {
        cin>>a>>b>>k;
        LL ans;
        LL l=0,r=k;
        while(l<=r)
        {
            LL mid=(l+r)>>1;
            if(check(mid)){
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

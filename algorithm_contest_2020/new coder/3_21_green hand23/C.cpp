#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
//补题：其实就是二分，连通！=强连通
//相乘/相除转换成double就不怕精度问题了；（最大值1e308，但是只有15~16位有效数字）
int main()
{
    int t;cin>>t;
    while(t--)
    {
        ULL m,n;
        cin>>n>>m;
        ULL l=1,r=n+1;
        ULL ans;
        
        while(l<r)
        {
            ULL mid=l+r>>1;
            if(double(2*n-mid)<=2.0*double(m)/double(mid-1)){
                ans=mid;
                l=mid+1;
                }
            else r=mid;
        }
        /*如果不换成double，可以让r =min(n,2*1e18/n),因为m<1e18，mid有取值的最大值（解不等式）*/
        cout<<ans<<endl;
    }
    return 0;
}
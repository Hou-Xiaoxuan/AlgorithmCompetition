#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
//���⣺��ʵ���Ƕ��֣���ͨ��=ǿ��ͨ
//���/���ת����double�Ͳ��¾��������ˣ������ֵ1e308������ֻ��15~16λ��Ч���֣�
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
        /*���������double��������r =min(n,2*1e18/n),��Ϊm<1e18��mid��ȡֵ�����ֵ���ⲻ��ʽ��*/
        cout<<ans<<endl;
    }
    return 0;
}
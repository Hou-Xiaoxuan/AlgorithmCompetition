#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
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
// 用神奇的map做这道题：
map<pair<pair<LL,LL>,LL>,LL> m1;
map<pair<LL,LL>,LL>m2;
LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
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
        m1.clear();
        m2.clear();
        LL n;cin>>n;
        LL ans=0;
        for(int i=1;i<=n;i++)
        {
            LL x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            LL A=y2-y1,B=x1-x2,C=x2*y1-x1*y2;
            LL g1=gcd(A,B);
            LL g2=gcd(A,gcd(B,C));
            m1[m_p(m_p(A/g2,B/g2),C/g2)]++;
            m2[m_p(A/g1,B/g1)]++;
        }
        ans=(n-1)*(n)/2;
        // 减去重合/平行的
        for(auto i:m2){
            ans-=i.second*(i.second-1)/2;
        }
        for(auto i:m1){
            ans+=i.second*(i.second-1)/2;
        }
        cout<<ans<<endl;
    }

    return 0;
}
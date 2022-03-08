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

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #endif
    
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,k;
        cin>>a>>b>>k;
        vector<P> pairs(k+1);
        for(int i=1;i<=k;i++) cin>>pairs[i].x;
        for(int i=1;i<=k;i++) cin>>pairs[i].y;
        vector<int> num_a(a+1),num_b(b+1);
        for(int i=1;i<=k;i++){
            num_a[pairs[i].x]++;
            num_b[pairs[i].y]++;
        }
        LL ans=LL(k)*(k-1);
        for(int i=1;i<=k;i++){
            LL tmp=num_a[pairs[i].x]+num_b[pairs[i].y]-2;
            ans-=tmp;;
        }
        ans/=2;
        cout<<ans<<endl;
    }
    return 0;
}

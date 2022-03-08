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
// AC
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #endif
    
    LL B,C;
    while(cin>>B>>C)
    {
        LL ans=0;
        if(B>0)
        {
            ans=C;
            if(C==1) ans++;
            ans+=min(C-2+1,2*B-1);
        }
        else if(B<0)
        {
            ans=C+1;
            ans+=max(min(-2*B-1,C-3+1),0ll);
        }
        else if(B==0)
        {
            ans=C;
        }
        cout<<ans<<endl;
    }
    return 0;
}

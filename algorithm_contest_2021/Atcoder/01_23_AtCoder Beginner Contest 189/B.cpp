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
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #elif _LINUX
    freopen("/media/linxuan/储存/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("/media/linxuan/储存/CODE/algorithm_contest/in.txt","r",stdin);
    #endif
    
    LL n,x;
    // while(cin>>n>>x)
    // CNM 多组输入会WA！！
    cin>>n>>x;
    {
        x*=100ll;
        int ans=-1;
        LL v,p;
        for(int i=1;i<=n;i++)
        {
            cin>>v>>p;
            x-=v*p;
            if(x<0 and ans==-1){
                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

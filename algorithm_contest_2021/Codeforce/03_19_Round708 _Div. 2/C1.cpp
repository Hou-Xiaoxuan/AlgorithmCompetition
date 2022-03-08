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
typedef long double LD;
const int inf=0x3f3f3f3f;


int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #elif _LINUX
    freopen("/run/media/linxuan/储存/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("/run/media/linxuan/储存/CODE/algorithm_contest/in.txt","r",stdin);
    #endif

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        //m==3
        if(n&1){
            cout<<1<<" "<<n/2<<" "<<n/2<<endl;
        }
        else
        {
            int tmp=1;
            while(n%2==0)
            {
                n/=2;
                tmp*=2;
            }
            if(n==1) cout<<tmp/4<<" "<<tmp/4<<" "<<tmp/2<<endl;
            else
            {
                cout<<tmp<<" "<<(n/2)*tmp<<" "<<(n/2)*tmp<<endl;
            }

        }
    }
    return 0;
}

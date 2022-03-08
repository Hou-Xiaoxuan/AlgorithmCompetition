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
using P=pair<int,bool>;
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
        int q,d;
        cin>>q>>d;
        for(int i=1;i<=q;i++)
        {
            int val; cin>>val;
            if(val>=d*10 or val%d==0){
                cout<<"Yes"<<endl;
                continue;
            }
            int cnt=val/d;
            int target=val%d;
            bool flag=false;
            for(int i=1;i<=cnt;i++)
            {
                if(i*d%10+target==d){
                    flag=true;
                    break;
                }    
            }
            if(flag) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }

    }
    return 0;
}

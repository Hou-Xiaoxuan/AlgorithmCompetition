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
    
    LL n;
    cin>>n;
    LL m=n<<1;
    LL cnt=0;
    for(int i=1;i<=sqrt(m);i++)
    {
        if(m%i==0)
        {
            LL tmp=i;
            if((tmp&1)==1 and ((m/tmp)&1)==0) cnt++;
            else if((tmp&1)==0 and ((m/tmp)&1)==1) cnt++;
            tmp=m/i;
            if(tmp!=i)
                if((tmp&1)==1 and ((m/tmp)&1)==0) cnt++;
                else if((tmp&1)==0 and ((m/tmp)&1)==1) cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}

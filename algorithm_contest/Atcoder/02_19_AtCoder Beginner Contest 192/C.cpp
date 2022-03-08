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


LL f(LL x)
{
    vector<int> a;
    while(x>0){
        a.push_back(x%10);
        x/=10;
    }
    LL g1=0,g2=0;
    sort(a.begin(),a.end());
    for(auto i:a){
        g2*=10;
        g2+=i;
    }
    reverse(a.begin(),a.end());
    for(auto i:a){
        g1*=10;
        g1+=i;
    }
    return g1-g2;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #endif
    
    LL n,k;
    cin>>n>>k;
    while(k--){
        n=f(n);
    }
    cout<<n<<endl;
    return 0;
}

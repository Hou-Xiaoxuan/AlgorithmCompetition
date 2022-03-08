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
    
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string b;
        cin>>b;
        vector<int> c(n);
        string a;
        a.push_back('1');
        c[0]=b[0]=='0'?1:2;
        for(int i=1;i<n;i++)
        {
            if(c[i-1]==1){
                if(b[i]=='1') a.push_back('1');
                else a.push_back('0');
            }
            else if(c[i-1]==2){
                if(b[i]=='1') a.push_back('0');
                else a.push_back('1');
            }
            else if(c[i-1]==0){
                a.push_back('1');
            }
            c[i]=a[i]+b[i]-'0'-'0';
        }
        cout<<a<<endl;
    }
    return 0;
}

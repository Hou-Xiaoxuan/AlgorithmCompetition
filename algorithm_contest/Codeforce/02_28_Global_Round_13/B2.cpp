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
    
    int t;  cin>>t;
    while(t--)
    {
        int n,u,v;
        cin>>n>>u>>v;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        const int m=1e6+1;
        bool flag=false;
        // 是否联通
        for(int i=2;i<=n;i++)
        {
            if(abs(a[i-1]-a[i]<=1)) continue;
            else{
                flag=true;
                break;
            }
        }
        if(flag==true){
            cout<<0<<endl;
            continue;
        }
        vector<int> ans;
        for(int i=1;i<=n;i++)
        {
            if((i!=1 and a[i-1]!=a[i]) or (i!=n and a[i+1]!=a[i])){
                ans.push_back(u);
                break;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if((i==1 and a[i+1]!=a[i]) or (i==n and a[i-1]!=a[i]) or (i!=1 and i!=n and a[i+1]!=a[i-1])){
                ans.push_back(v);
                break;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if((i==1 and a[i+1]==a[i]) or (i==n and a[i-1]==a[i]) or (i!=1 and i!=n and a[i]==a[i-1] and a[i]==a[i+1])){
                ans.push_back(2*v);
            }
        }
        ans.push_back(u+v);
        cout<<*min_element(ans.begin(),ans.end())<<endl;
    }
    return 0;
}

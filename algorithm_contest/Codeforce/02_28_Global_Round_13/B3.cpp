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
        int ans=inf;
        for(int i=1;i<=n;i++)
        {
            if((i!=1 and a[i-1]!=a[i]) or (i!=n) and a[i+1]!=a[i]) ans=min(ans,u);

            a[i]++;
            if((i!=1 and abs(a[i-1]-a[i])>1) or (i!=n and abs(a[i+1]-a[i])>1)) ans=min(ans,v);
            else
            {
                if((i!=1 and a[i-1]!=a[i]) or (i!=n) and a[i+1]!=a[i]) ans=min(ans,v+u);
                if(a[i]!=m)
                {

                    a[i]++;
                    if((i!=1 and abs(a[i-1]-a[i])>1) or (i!=n and abs(a[i+1]-a[i])>1)) ans=min(ans,v+v);
                    a[i]--;
                }
            }
            a[i]--;

            a[i]--;
            if((i!=1 and abs(a[i-1]-a[i])>1) or (i!=n and abs(a[i+1]-a[i])>1)) ans=min(ans,v);
            else
            {
                if((i!=1 and a[i-1]!=a[i]) or (i!=n) and a[i+1]!=a[i]) ans=min(ans,v+u);
                if(a[i]!=0)
                {
                    a[i]--;
                    if((i!=1 and abs(a[i-1]-a[i])>1) or (i!=n and abs(a[i+1]-a[i])>1)) ans=min(ans,v+v);
                    a[i]++;
                }
            }
            a[i]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

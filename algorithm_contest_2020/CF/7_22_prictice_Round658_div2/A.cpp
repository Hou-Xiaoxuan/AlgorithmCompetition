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
const int inf=0x3f3f3f3f;
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    int t;cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int ans=-1;
        set<int> se;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            se.insert(x);
        }
        for(int i=1;i<=m;i++){
            int y;cin>>y;
            if(se.count(y)==1)
                ans=y;
        }
        if(ans==-1) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl<<1<<" "<<ans<<endl;
        }
    }
    return 0;
}
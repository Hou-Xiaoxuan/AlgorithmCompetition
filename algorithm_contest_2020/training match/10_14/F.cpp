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
    int cnt=1;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int ans1=inf,ans2=inf;
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            ans1=min(ans1,x);
        }
         for(int i=1;i<=m;i++){
            int x;cin>>x;
            ans2=min(ans2,x);
        }
        cout<<"Problem "<<1000+cnt++<<":"<<endl;
        cout<<"Shortest judge solution: "<<ans1<<" bytes."<<endl;
        if(m==0) cout<<"Shortest team solution: N/A"<<" bytes."<<endl;
        else cout<<"Shortest team solution: "<<ans2<<" bytes."<<endl;


    }
    return 0;
}
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
//>
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
        int n,m,p;
        cin>>n>>m>>p;
        int ans=0;

        // while(n>=m)
        // {
        //     int cnt=n/m;
        //     ans+=cnt;
        //     n=n%m;
        //     n+=m*(1-double(p)/100)*cnt;
        // }
        // cout<<ans<<endl;

        /*-------*/
        // int tmp[2]={m,m};
        // for(int i=m;i<=m+100;i++)
        //     if(i-int(i*(1-double(p)/100))<=tmp[0])
        //         tmp[0]=i-int(i*(1-double(p)/100)),tmp[1]=i;
        // // cout<<m<<" "<<p<<":"<< tmp[0]<<"--"<<tmp[1]<<endl;
        // int pie=tmp[1];//æ¯�æ¬¡æŠ•å…¥pie
        // while(n>=m)
        // {
        //     while(n>=pie)
        //     {
        //         int cnt=n/pie;
        //         ans+=cnt;
        //         n-=cnt*pie;
        //         n+=cnt*int(pie*(1-double(p)/100));
        //     }
        //     if(n>=m)
        //     {
        //         n-=m;
        //         ans++;
        //         n+=int(m*(1-double(p)/100));
        //     }
        // }
        // cout<<ans<<endl;

        while(n>=m)
        {
            //这样真的能过？？
            ans++;
            n-=m;
            n+=m*(100-p)/100;
            //草，想哭…………
        }
        cout<<ans<<endl;
    }
    return 0;
}
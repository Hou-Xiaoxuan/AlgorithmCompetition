#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<LL,LL>
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

    int n;
    while(cin>>n)
    {
        vector<pair<P,P>> a(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].x.x>>a[i].x.y;
            a[i].y.x=i;
        }
        sort(a.begin()+1,a.end(),[](const pair<P,P> a,const pair<P,P> b)->bool{
            if(a.x.x*a.x.y==b.x.x*b.x.y)
            {
                if(a.x.x==b.x.x)
                    return a.y.x<b.y.x;
                else
                    return a.x.x>b.x.x;
            }
            else
                return a.x.x*a.x.y>b.x.x*b.x.y;
        });
        for(int i=1;i<=n;i++){
            // a[i].y.y=i;
            cout<<a[i].y.x<<" ";
        }cout<<endl;
        // sort(a.begin()+1,a.end(),[](const pair<P,P> a,const pair<P,P> b)->bool{
        //     return a.y.x<b.y.x;
        // });
        // for()
    }
    return 0;
}

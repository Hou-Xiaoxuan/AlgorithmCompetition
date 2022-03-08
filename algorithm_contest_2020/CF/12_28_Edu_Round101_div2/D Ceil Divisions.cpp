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
// 补题：通过连续开方，LL范围内的数刚好在6次内变成1

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    int t;
    cin>>t;
    // 
    while(t--)
    {
        int n;cin>>n;
        vector<P> ans;
        int a=n;
        int b=n-1;
        while(b>1)
        {
            if(b<=sqrt(a)+1)
            {
                ans.push_back(P(a,b));
                ans.push_back(P(a,b));
                a=b;
            }
            else ans.push_back(P(b,a));
            b--;
        }
        cout<<ans.size()<<endl;
        for(auto st:ans)
            cout<<st.x<<" "<<st.y<<endl;
    }
    return 0;
}

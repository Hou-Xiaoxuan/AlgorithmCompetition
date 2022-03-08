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
// 直接去玩了……我也太容易满足了吧。这题好像不难，说不能能直接上1500的
// 题解：特判区域，计算，没了……
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    LL c[7];
    int t;cin>>t;
    while(t--)
    {
        pair<LL,LL> st;
        cin>>st.x>>st.y;
        for(int i=1;i<=6;i++) cin>>c[i];
        for(int i=1;i<=6;i++)
            c[i]=min(c[i],c[(i-1+6-1)%6+1]+c[(i+1-1)%6+1]);
        if(st.x>=0 and st.y>=0)
        {
            if(st.x>st.y) cout<<(st.x-st.y)*c[6]+st.y*c[1]<<endl;
            else cout<<(st.y-st.x)*c[2]+st.x*c[1]<<endl; 
        }
        else if(st.x<=0 and st.y<=0)
        {
            st.x*=-1;
            st.y*=-1;
            if(st.x>st.y) cout<<(st.x-st.y)*c[3]+st.y*c[4]<<endl;
            else cout<<(st.y-st.x)*c[5]+st.x*c[4]<<endl; 
        }
        else
        {
            if(st.x>0) cout<<st.x*c[6]+(-st.y)*c[5]<<endl;
            else cout<<st.y*c[2]+(-st.x)*c[3]<<endl;
        }
    }
    return 0;
}
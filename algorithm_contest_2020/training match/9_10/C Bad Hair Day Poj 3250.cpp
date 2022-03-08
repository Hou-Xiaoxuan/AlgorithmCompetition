#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;
// LL
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
        vector<LL> a(n+2);
        for(int i=1;i<=n;i++) cin>>a[i];
        n++;a[n]=inf;
        stack<LL> st;
        st.push(1);
        LL ans=0;
        for(int i=2;i<=n;i++)
        {
            while(st.size()!=0 and a[i]>=a[st.top()]){
                ans+=i-st.top()-1;
                // cout<<"debug: "<<i-st.top()-1<<endl;
                st.pop();
            }
            st.push(i);
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
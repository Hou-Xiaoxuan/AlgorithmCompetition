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

    int n;
    cin>>n;
    auto cmp=[](const P&a,const P&b)->bool{
        if(a.second==b.second)
            return a.x>b.x;
        return a.second<b.second;
    };
    vector<bool> vis(n+1);
    int tot=0;
    priority_queue<P,vector<P>,greater<P>> que1;
    priority_queue<P,vector<P>,decltype(cmp)> que2(cmp);
    for(int t=1;t<=n;t++)
    {
        int ques,value;
        cin>>ques;
        if(ques==1)
        {
            cin>>value;
            que1.push(m_p(++tot,value));
            que2.push(m_p(tot,value));
        }
        else if(ques==2)
        {
            while(vis[que1.top().x]==true) que1.pop();
            P st=que1.top();
            que1.pop();
            vis[st.x]=true;
            cout<<st.x<<" ";
        }
        else if(ques==3)
        {
            while(vis[que2.top().x]==true) que2.pop();
            P st=que2.top();
            que2.top();
            vis[st.x]=true;
            cout<<st.x<<" ";
        }
    }
    return 0;
}

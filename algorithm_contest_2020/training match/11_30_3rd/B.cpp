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

// 同分异构体……
// 储存每个点到最远的点的距离
// 从队列里不断取出,且之前点的数据不用维护
const int N=5e4;
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif

    LL n,k,d;
    while(cin>>n>>d>>k)
    {
        if(n==1){
            cout<<"Yes"<<endl;
            continue;
        }
        vector<int> du(n+1);
        vector<int> dis(n+1);
        queue<int> que;
        que.push(1);
        que.push(2);
        int t=3;
        vector<P> ans;
        ans.push_back(P(1,2));
        dis[1]=dis[2]=1;
        du[1]=du[2]=1;
        while(t<=n and !que.empty())
        {
            int u=que.front();
            que.pop();
            if(du[u]>=k or dis[u]>=d) continue;
            while(t<=n and du[u]<k){
                ans.push_back(P(u,t));
                du[u]++;
                du[t]++;
                dis[t]=dis[u]+1;
                if(dis[u]==0) dis[u]=1;
                que.push(t);
                t++;
            }
        }
        if(ans.size()<n-1){
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
            for(auto st:ans)
                cout<<st.x<<" "<<st.y<<endl;
        }
    }
    
    return 0;
}

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<LL,LL>
#define to first
#define weight second 
typedef long long LL;
typedef unsigned long long ULL;
// const LL inf=0x3f3f3f3f3f3f3f3f;
const LL inf=4223372036854775807ll; 

/*
* 题解：多源最短路
* 先一遍SPFA求出每个点到最近的1的距离(1本身即是0)。
* 然后枚举边，如果一条边的两边分别是不同的1，则用来更新答案
*/
// 好神奇啊
const int N=1e5;
vector<P> edg[N+5];

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif

    int n,m;
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++) vector<P>().swap(edg[i]);

        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];

        for(int i=1;i<=m;i++){
            LL u,v,w;
            cin>>u>>v>>w;
            edg[u].push_back(m_p(v,w));
            edg[v].push_back(m_p(u,w));
        }

        // SPFA多源最短路
        vector<bool> vis(n+1);
        vector<LL> pre(n+1,-1),dis(n+1,inf);
        queue<int> que;
        for(int i=1;i<=n;i++)
            if(a[i]==1)//将1作为'源'
            {
                dis[i]=0;
                pre[i]=i;
                vis[i]=true;
                que.push(i);
            }
        while(!que.empty())
        {
            int st=que.front();
            que.pop();
            vis[st]=false;
            for(auto u:edg[st])
            {
                if(dis[u.to]>dis[st]+u.weight)
                {
                    pre[u.to]=pre[st];
                    dis[u.to]=dis[st]+u.weight;
                    if(vis[u.to]==false){
                        que.push(u.to);
                        vis[u.to]=true;
                    }
                }
            }
        }

        // 查找答案
        LL ans=inf,l,r;
        for(int i=1;i<=n;i++)
        {
            for(auto st:edg[i])
            {
                if(pre[i]!=pre[st.to] and pre[i]!=-1 and pre[st.to]!=-1)
                {
                    if(ans>dis[i]+dis[st.to]+st.weight)
                    {
                        ans=dis[i]+dis[st.to]+st.weight;
                        l=pre[i],r=pre[st.to];
                    }
                }
            }
        }
        
        // 输出
        if(ans>=inf)
            cout<<"No luck at all"<<endl;
        else cout<<ans<<endl<<l<<" "<<r<<endl;
    }
    return 0;
}

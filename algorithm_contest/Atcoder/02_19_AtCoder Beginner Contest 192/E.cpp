#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define x first
#define y second 
using namespace std;
using LL=long long;
using ULL=unsigned long long;
using LD=long double;
using P=pair<int,int>;
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;
// AC
// 该到最后，发现不用改，差一个LL而已
struct E
{
    int u,v;
    LL k,t;
};
vector<LL> dis;
vector<vector<E>> edg;
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #endif
    
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    
    edg.assign(n+1,vector<E>());
    for(int i=1;i<=m;i++){
        E st;
        cin>>st.u>>st.v>>st.t>>st.k;
        edg[st.u].push_back(st);
        swap(st.u,st.v);
        edg[st.u].push_back(st);
    }
    dis.assign(n+1,LLinf);
    vector<bool> vis(n+1,0);
    dis[x]=0;
    vis[x]=true;
    queue<int> que;
    que.push(x);
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        vis[u]=false;
        for(auto e:edg[u])
        {   
            LL k=(dis[u]-1)/e.k+1;//k要用LL，否则会wA4个点
            if(dis[u]==0) k=0;
            if(dis[e.v]>k*e.k+e.t)
            {
                dis[e.v]=k*e.k+e.t;
                if(vis[e.v]==false)
                    que.push(e.v);
            }
        }
    }
    cout<<(dis[y]==LLinf?-1:dis[y])<<endl;
    return 0;
}

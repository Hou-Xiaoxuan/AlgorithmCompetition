#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
const int inf=0x3f3f3f3f;

bool SPFA(int n,int m,int st,vector<vector<pair<int,int>> >&edg,vector<int>& dis)//点数，边数，起始点，邻接表存边，距离的参数
{
    
	vector<int> num(n+1);
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edg[u].push_back(pair(v,w));
        // edg[v].push_back(u);//无向图
    }
    queue<int> que;
    que.push(st);
    fill(dis.begin(),dis.end(),inf);
    dis[st]=0;
    while (!que.empty())
    {
        int u=que.front();
        num[u]++;
        if(num[u]>=n) return false;//存在环
        for(auto e:edg[u])
            if(dis[u]+e.second<dis[e.first])
            {
                dis[e.first]=dis[u]+e.second;
                que.push(e.first);
            }
    }
    return true;//没有负权环
}

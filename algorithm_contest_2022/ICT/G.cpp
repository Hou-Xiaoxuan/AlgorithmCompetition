/*
 * @Author: linxuan
 * @Date: 2022-07-19 22:42:17
 * @Description: 网络流
 * @FilePath: /Algorithm/algorithm_contest_2022/ICT/G.cpp
 */
# ifndef _USE_MATH_DEFINES
# define _USE_MATH_DEFINES
# endif
# include<bits/stdc++.h>
# define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
# define  m_p make_pair
# define x first
# define y second 
using namespace std;
using LL=long long;
using ULL=unsigned long long;
using LD=long double;
using P=pair<int,int>;
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;

struct Edge
{
    int to;
    int rev;
    LL cap;
};
vector<vector<Edge>> graph;

LL dfs(int from, int target, LL flow)
{
    LL nowflow = 0;
    if(from == target) return flow;

    for(size_t i=0; i<graph[from].size(); i++)
    {
        Edge & edge = graph[from][i];
        if(flow == 0) break;
        if(edge.cap > 0)
        {
            LL newflow = dfs(edge.to, target, min(flow - nowflow, graph[from][i].cap));
            if(newflow>0){
                edge.cap -= newflow;
                graph[edge.to][edge.rev].cap += newflow;
                nowflow += newflow;
            }
            break;
        }
    }
    return nowflow;
}
int main()
{
    int n; cin>>n;
    graph.resize(n + 2);
    for(int i=1; i<=n; i++)
    {
        int m; cin>>m;
        for(int j=1; j<m; j++)
        {
            int to; cin>>to;
            Edge e1 = {to, (int)graph[to].size(), 1};
            Edge e2 = {i, (int)graph[i].size(), 1};
            graph[i].push_back(e1);
            graph[to].push_back(e2);
        }
    }
    for(int i=1; i<=n; i++){
        Edge e1 = {n + 1, (int)graph[n + 1].size(), 1};
        Edge e2 = {i, (int)graph[i].size(), 1};
        graph[i].push_back(e1);
        graph[n + 1].push_back(e2);
    }

    return 0;
}

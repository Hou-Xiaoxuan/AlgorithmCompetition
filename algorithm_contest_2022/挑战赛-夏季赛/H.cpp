/*
 * @Author: linxuan
 * @Date: 2022-07-24 09:55:53
 * @Description: file content
 * @FilePath: /Algorithm/algorithm_contest_2022/挑战赛-夏季赛/H.cpp
 */
#ifndef _USE_MATH_DEFINES
 #define _USE_MATH_DEFINES
#endif
#include <bits/stdc++.h>
#define IOS                   \
 ios::sync_with_stdio(false); \
 cin.tie(0);                  \
 cout.tie(0);
#define m_p make_pair
#define x   first
#define y   second
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using LD = long double;
using P = pair<int, int>;
const int inf = 0x3f3f3f3f;
const LL LLinf = 0x3f3f3f3f3f3f3f3f;

struct Edge {
    int to;
    int w;
};

int main()
{
    IOS;
#ifdef _DEBUG
    // freopen("out.txt", "w", stdout);
    freopen("in.txt", "r", stdin);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<Edge>> graph(n * (k + 1) + 1);
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        for (int i = 0; i <= k; i++)
        {
            // 层内的边
            graph[x + i * n].push_back({y + i * n, z});
            graph[y + i * n].push_back({x + i * n, z});

            if(i != k) // 层之间边权为0的边
            {
                graph[x + i * n].push_back({y + (i + 1) * n, 0});
                graph[y + i * n].push_back({x + (i + 1) * n, 0});
            }
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;    // 权重，点编号
    vector<int> dis(graph.size(), inf);
    vector<bool> vis(graph.size(), false);

    dis[1] = 0;    // 默认起点
    que.push({0, 1});
    while (que.empty() == false)
    {
        int st = que.top().second;
        que.pop();
        vis[st] = true;

        for (auto &e : graph[st])
        {
            if (vis[e.to] == false && dis[e.to] > dis[st] + e.w)
            {
                dis[e.to] = dis[st] + e.w;
                que.push({dis[e.to], e.to});
            }
        }
    }

    int ans = inf;
    for (int i = 0; i <= k; i++)
    {
        ans = min(ans, dis[i * n + n]);
    }
    cout << ans << endl;
    return 0;
}

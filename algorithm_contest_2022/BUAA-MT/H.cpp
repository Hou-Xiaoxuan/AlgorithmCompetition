/*
 * @Author: linxuan
 * @Description: H题补题，https://ac.nowcoder.com/acm/contest/403/A 原题
 * @FilePath: /Algorithm/algorithm_contest_2022/BUAA-MT/H.cpp
 */
#ifndef _USE_MATH_DEFINES
 #define _USE_MATH_DEFINES
#endif
#include <bits/stdc++.h>
#define IOS                   \
 ios::sync_with_stdio(false); \
 cin.tie(0);                  \
 cout.tie(0);
// #define m_p make_pair
// #define x   first
// #define y   second
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using LD = long double;
using P = pair<int, int>;
const int inf = 0x3f3f3f3f;
const LL LLinf = 0x3f3f3f3f3f3f3f3f;
/*使用优先队列，从最低点来进行bfs。
 * 由于每个点只能更新一次，因此每个点都能被更新为边界的最小值
 */
int main()
{
    IOS;
#ifdef _DEBUG
    // freopen("out.txt","w",stdout);
    freopen("in.txt", "r", stdin);
#endif

    struct Node {
        int x, y;
        LL value;
        Node(int _x, int _y, int _val) : x(_x), y(_y), value(_val) { }
        bool operator<(const Node &rhs) const { return this->value > rhs.value; }
    };

    priority_queue<Node> que;
    int n, m;
    cin >> n >> m;
    vector<vector<LL>> matrix(n + 1, vector<LL>(m + 1));
    vector<vector<LL>> height(n + 1, vector<LL>(m + 1));
    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1));


    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> matrix[i][j];
            if (i == 1 or i == n or j == 1 or j == m)
            {
                height[i][j] = matrix[i][j];
                que.emplace(i, j, matrix[i][j]);
                vis[i][j] = true;
            }
        }

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    while (que.empty() == false)
    {
        auto st = que.top();
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = st.x + dx[i];
            int ny = st.y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny] == true)
                continue;
            vis[nx][ny] = true;
            height[nx][ny] = max(matrix[nx][ny], st.value);
            que.emplace(nx, ny, height[nx][ny]);
        }
    }
    LL ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans += height[i][j] - matrix[i][j];
    cout << ans << endl;
    // // 打印matrix和height
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //         cout << matrix[i][j] << " ";
    //     cout << endl;
    // }
    //  cout<<endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //         cout << height[i][j] << " ";
    //     cout << endl;
    // }
    return 0;
}

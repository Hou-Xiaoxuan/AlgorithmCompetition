/*
 * @Author: linxuan
 * @Date: 2022-07-24 11:10:24
 * @Description: file content
 * @FilePath: /Algorithm/algorithm_contest_2022/挑战赛-夏季赛/C.cpp
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


int main()
{
    IOS;
#ifdef _DEBUG
    // freopen("out.txt","w",stdout);
    freopen("in.txt", "r", stdin);
#endif
    int n, m, limit;
    cin >> n >> m >> limit;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0)), b(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == 'N')
                a[i][j] = 1;
            else if (ch == 'T')
                b[i][j] = 1;
            // 求二维前缀和
            a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
            b[i][j] += b[i][j - 1] + b[i - 1][j] - b[i - 1][j - 1];
        }
    }
    int ans = -1;
    // 遍历起点
    for (int si = 1; si <= n; si++)
    {
        for (int sj = 1; sj <= m; sj++)
        {
            for (int ti = si; ti <= n; ti++)
            {
                for (int tj = sj; tj <= m; tj++)
                {
                    int num_a = a[ti][tj] - a[ti][sj - 1] - a[si - 1][tj] + a[si - 1][sj - 1];
                    int num_b = b[ti][tj] - b[ti][sj - 1] - b[si - 1][tj] + b[si - 1][sj - 1];
                    if (abs(num_a - num_b) <= limit)
                        ans = max(ans, num_a + num_b);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

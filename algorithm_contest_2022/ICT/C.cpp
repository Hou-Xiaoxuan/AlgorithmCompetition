/*
 * @Author: linxuan
 * @Date: 2022-07-19 20:44:13
 * @Description: file content
 * @FilePath: /Algorithm/algorithm_contest_2022/ICT/C.cpp
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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> f(n + 1, vector<int>(m + 1));    // i个盒子,j个球
    f[1][1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= min(i, m); j++)
            f[i][j] = j * (f[i - 1][j] + f[i - 1][j - 1]);
    cout << f[n][m] << endl;
    return 0;
}

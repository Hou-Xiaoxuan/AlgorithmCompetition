/*
 * @Author: linxuan
 * @Date: 2022-07-19 23:13:39
 * @Description: 思路简单，但是用cin读会有奇怪bug
 * @FilePath: /Algorithm/algorithm_contest_2022/ICT/E.cpp
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
#ifdef _DEBUG
    // freopen("out.txt", "w", stdout);
    freopen("in.txt", "r", stdin);
#endif
    LL ans[2] {0, 1};
    int n;
    cin >> n;
    while (n--)
    {
        // 读入一个用'/'区分的分数
        string s;
        cin >> s;
        int len = s.size();
        int i = 0;
        LL a = 0, b = 0;
        while (i < len && s[i] != '/')
        {
            a *= 10;
            a += s[i] - '0';
            i++;
        }
        i++;
        while (i < len)
        {
            b *= 10;
            b += s[i] - '0';
            i++;
        }
        // string s;
        // cin >> s;
        // size_t pos = s.find('/');
        // LL a = stoll(s.substr(0, pos));
        // LL b = stoll(s.substr(pos + 1));
        // LL a, b;
        // scanf("%lld/%lld", &a, &b);
        ans[0] = ans[0] * b + ans[1] * a;
        ans[1] = ans[1] *  b;
        LL d = __gcd(ans[0], ans[1]);
        ans[0] /= d;
        ans[1] /= d;
    }
    // cout << ans[0] << "/" << ans[1];
    printf("%lld/%lld\n", ans[0], ans[1]);
    return 0;
}

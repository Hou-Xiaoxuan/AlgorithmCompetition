#ifndef _USE_MATH_DEFINES
 #define _USE_MATH_DEFINES
 #include <cmath>
 #include <cstdlib>
#endif
#include <bits/stdc++.h>
#define IOS                   \
 ios::sync_with_stdio(false); \
 cin.tie(0);                  \
 cout.tie(0);
#define x first
#define y second
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using LD = long double;
using P = pair<int, int>;
const int inf = 0x3f3f3f3f;
const LL LLinf = 0x3f3f3f3f3f3f3f3f;
vector<LL> fabnachi(2e5, 0);
int max_k;
LL gcd(LL a, LL b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

LL exgcd(LL a, LL b, LL &x, LL &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    LL r = exgcd(b, a % b, x, y);
    LL t = x;
    x = y;
    y = t - a / b * y;
    return r;
}


int main()
{
    IOS;
    int max_n = 1e7;
    fabnachi[1] = 1;
    fabnachi[2] = 1;
    for (int i = 3; i < max_n; i++)
    {
        fabnachi[i] = fabnachi[i - 1] + fabnachi[i - 2];
        if (fabnachi[i] > max_n)
        {
            max_k = i;
            break;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
#ifdef _DEBUG
        cout << "ans = ";
#endif
        if (k > max_k)
        {
            cout << "0" << endl;
            continue;
        }
        LL a = fabnachi[k - 2], b = fabnachi[k - 1], c = n;
        LL r_abc = gcd(a, gcd(b, c));
        a /= r_abc;
        b /= r_abc;
        c /= r_abc;

        LL x, y;
        LL r_ab = exgcd(a, b, x, y);
        // 无解
        if (c % r_ab != 0)
        {
            cout << "0" << endl;
            continue;
        }

        LL x0 = x * c / r_ab, y0 = y * c / r_ab;    // ax + by = c的一组整数解
        /*推不明白公式，暴力了*/
        LL d = a * b / r_ab;
        LL y_sub = d / b;
        LL x_sub = d / a;
        LL min_x = x0, max_y = y0;
        if (min_x < 0)
        {
            min_x = (min_x % x_sub + x_sub) % x_sub;
            max_y = (c - a * min_x) / b;
        }
        while (min_x - x_sub >= 0)
        {
            min_x -= x_sub;
            max_y += y_sub;
        }

        int ans = 0;
        LL ct_x = min_x, ct_y = max_y;
        while (ct_x <= ct_y)
        {
            ans++;
            ct_x += x_sub;
            ct_y -= y_sub;
        }
        cout << ans << endl;
    }
}
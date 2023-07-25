#ifndef _USE_MATH_DEFINES
 #define _USE_MATH_DEFINES
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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k, h;
        cin >> n >> m >> k >> h;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int num;
            cin >> num;
            int diff = abs(num - h);
            if (diff > 0 and diff < k * m and diff % k == 0)
                ans++;
        }
#ifdef _DEBUG
        cout << "\nans = ";
#endif
        cout << ans << endl;
    }
    return 0;
}

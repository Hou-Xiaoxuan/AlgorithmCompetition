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
    IOS;
#ifdef _DEBUG
    // freopen("out.txt","w",stdout);
    freopen("in.txt", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> a(n + 1);

        int min_value = inf, min_index = -1;
        int min_2_value = inf, min_2_index = -1;
        LL ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int m;
            cin >> m;
            a[i].resize(m);
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
            sort(a[i].begin(), a[i].end());
            if (a[i][0] < min_value)
            {
                min_value = a[i][0];
                min_index = i;
            }
            if (a[i][1] < min_2_value)
            {
                min_2_value = a[i][1];
                min_2_index = i;
            }
            ans += a[i][1];
        }
        ans = ans + min_value - min_2_value;
        cout << ans << endl;
    }

    return 0;
}
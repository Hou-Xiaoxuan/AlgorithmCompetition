#ifndef _USE_MATH_DEFINES
 #define _USE_MATH_DEFINES
 #include <cmath>
#endif
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
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
        int n;
        cin >> n;
        vector<int> a(n + 1);
        int num = inf;
        cin >> a[1];
        for (int i = 2; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] < a[i - 1])
                num = -1;
            else
                num = min(num, a[i] - a[i - 1]);
        }
        // cout<<"ans ";
        if (num < 0)
            cout << 0 << endl;
        else
        {
            // 向上取整
            cout << num / 2 + 1 << endl;
        }
    }
}

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
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while ((t--))
    {
        /* code
         */
        int a, b, c;
        cin >> a >> b >> c;
        cout << min(a - 1, b + c) * 2 + 1 << endl;
    }

    return 0;
}
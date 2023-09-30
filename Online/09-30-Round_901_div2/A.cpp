#ifndef _USE_MATH_DEFINES
 #define _USE_MATH_DEFINES
#endif
#include <bits/stdc++.h>
#define IOS                         \
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
        LL a, b, n;
        cin >> a >> b >> n;
        LL ans = b;    // 怎么会有傻逼中间变量用long long，结果用int存啊！！
        while (n--)
        {
            LL x;
            cin >> x;
            // 1 + x <=a,c set to 1+x. increase c - 1 second, value is x
            // 1 + x > a, c set to a, increase c - 1 second, value is a - 1
            ans += min(a - 1, x);
        }
        cout << ans << endl;
    }
    return 0;
}
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
    int m, n, k;
    cin >> t;
    while ((t--))
    {
        /* code */
        cin >> n >> m >> k;
        vector<int> a(n + 1), b(m + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int j = 1; j <= m; j++)
            cin >> b[j];
        int min_a = *min_element(a.begin() + 1, a.end());
        int min_b = *min_element(b.begin() + 1, b.end());
        int max_a = *max_element(a.begin() + 1, a.end());
        int max_b = *max_element(b.begin() + 1, b.end());
        LL sum_a = accumulate(a.begin() + 1, a.end(), 0ll);
        LL sum_b = accumulate(b.begin() + 1, b.end(), 0ll);

        /*
            1. min belong to a, max belong to b，交换这俩踢皮球
            2. max belong to a, min belong to b，自己最小交换对方最大后，对对方来说属于1
            3. min and max belong to a: 交换一轮后，对对方来说属于1
            4. min and max belong to b: 交换一轮后，对对方来说属于2
        */

        // if (min_a <= min_b && max_b >= max_a)
        // {
        //     if (k & 1)    // 最大在自己，最小归对方
        //         cout << sum_a + max(-min_a + max_b, 0) << endl;
        //     else    // 最小归自己，最大归对方，没有变化
        //         cout << sum_a << endl;
        // }
        // else if (max_a >= max_b && min_b <= min_a)
        // {
        //     if (k & 1)    // 交换一轮后保持不变
        //         cout << sum_a + max(-min_a + max_b, 0) << endl;
        //     else    // 交换一轮后，最小归自己，最大归对方
        //         cout << sum_a + max(-min_a + max_b, 0) - max_a + min_b << endl;
        // }
        // else if (min_a <= min_b and max_a >= max_b)
        // {
        //     if (k & 1)    // 交换一轮后，保持不变
        //         cout << sum_a + max(-min_a + max_b, 0) << endl;
        //     else    // 交换一轮后，最小归自己，最大归对方
        //         cout << sum_a + max(-min_a + max_b, 0) - max_a + min_a << endl;
        // }
        // else if (min_b <= min_a and max_b >= max_a)
        // {
        //     if (k & 1)    // 交换一轮后，保持不变
        //         cout << sum_a + max(-min_a + max_b, 0);
        //     else
        //         cout << sum_a + min_b - min_a;    // 自己拿全局最小
        // }
    }

    return 0;
}
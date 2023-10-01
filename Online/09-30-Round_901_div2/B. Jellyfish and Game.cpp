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
        auto min_a = min_element(a.begin() + 1, a.end());
        auto max_b = max_element(b.begin() + 1, b.end());


        /*
            1. min belong to a, max belong to b，交换这俩踢皮球
            2. max belong to a, min belong to b，自己最小交换对方最大后，对对方来说属于1
            3. min and max belong to a: 交换一轮后，对对方来说属于1
            4. min and max belong to b: 交换一轮后，对对方来说属于2
        */

        // tutorial: 他们就是固定交换策略的，用自己最小的去交换对方最大的。随意只需要判断第一次是否交换就可以了。
        if (*min_a < *max_b)    // 第一轮jelly交换
            // swap(*min_a, *max_b);
            iter_swap(min_a, max_b);
        if (not(k & 1))
        {    // 对方能交换回去
            auto min_b = min_element(b.begin() + 1, b.end());
            auto max_a = max_element(a.begin() + 1, a.end());
            swap(*min_b, *max_a);
        }
        cout << accumulate(a.begin() + 1, a.end(), 0ll) << endl;
    }

    return 0;
}
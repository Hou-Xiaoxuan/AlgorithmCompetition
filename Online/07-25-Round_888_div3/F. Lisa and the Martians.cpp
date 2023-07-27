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
        int n, k;
        cin >> n >> k;
        struct pair {
            int num;
            int index;
            bool operator<(const pair &b) const { return num < b.num; }
        };
        vector<pair> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].num;
            a[i].index = i;
        }
        sort(a.begin() + 1, a.end());
       
       /*solve below*/
        // 猜错了结论，正确结论：数组中任意两数异或的最小值一定是排序后的相邻数的异或

        return 0;
}

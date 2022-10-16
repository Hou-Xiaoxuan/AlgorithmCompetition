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
class TreeArray
{
    vector<int> c;
    int n;
    int lowbit(int x) { return x & (-x); }

public:
    TreeArray(int n) : n(n) { c.resize(n + 1); }
    void init(vector<int> &a)
    {
        n = a.size();
        c.resize(n + 1);
        for (int i = 0; i < n; i++)
            add(i, a[i]);
    }
    void add(int x, int v)
    {
        for (int i = x; i <= n; i += lowbit(i))
            c[i] += v;
    }
    int sum(int x)
    {
        int res = 0;
        for (int i = x; i > 0; i -= lowbit(i))
            res += c[i];
        return res;
    }
};
// 快速幂
LL qpow(LL a, LL b, LL mod)
{
    LL res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b = b >> 1;
    }
    return res;
}
LL get_value(LL x, LL mod)
{
    static vector<long long> cach;
    if (cach.empty())
    {
        cach = vector<long long>(2e5 + 5, 0);
        cach[0] = 1;
        for (size_t i = 1; i < cach.size(); i++)
        {
            cach[i] = cach[i - 1] * i % mod;
        }
    }
    return cach[x];
};
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    long long ans = 0u;
    long long mod = 998244353;


    TreeArray tree(m + 5);
    auto get_A = [&](int a, int b) -> long long {
        // return 排列数 A(a, b)
        return get_value(a, mod) * qpow(get_value(a - b, mod), mod - 2, mod) % mod;
    };
    for (int i = 0; i < n; i++)
    {
        int cnt = tree.sum(a[i]);
        ans += cnt * get_A(m - i - 1, n - i - 1) % mod;
        tree.add(a[i], 1);
    }
    cout << ans << endl;
    return 0;
}

#ifndef _USE_MATH_DEFINES
 #define _USE_MATH_DEFINES
#endif
// #include <bits/stdc++.h>
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

// 并查集 类
class UnionFind
{
    vector<int> fa;
    int groups;

public:
    UnionFind(int n) : fa(n), groups(n)
    {
        for (int i = 0; i < n; i++)
            fa[i] = i;
    }
    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
    void unite(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if (fx != fy)
        {
            fa[fx] = fy;
            groups--;
        }
    }
    inline int getGroups() { return groups; }
};

// 快速幂
LL qmod(LL a, LL b, LL mod)
{
    LL ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
#ifdef _DEBUG
    freopen("input", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
        i--;
    }

    long long ans = 0u;
    const long long mod = 998244353;

    UnionFind uf(n);
    for (int i = 0; i < n; i++)
    {
        if (uf.find(i) == uf.find(a[i]))
            continue;
        // b[i] < b[a[i]], 这两个特殊选择，i之前的组合相等
        int times = uf.getGroups() - 2;
        // A(m, 2)/2*m^times%mod
        // SB, m类型int， (m-1)*m/2就炸了
        ans += (m - 1ll) * m / 2ll % mod * qmod(m, times, mod) % mod;
        ans%=mod;
        uf.unite(i, a[i]);
    }
    cout << ans << endl;
    return 0;
}

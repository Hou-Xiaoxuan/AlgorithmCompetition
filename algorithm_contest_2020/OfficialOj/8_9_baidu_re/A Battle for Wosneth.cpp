#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <bits/stdc++.h>
using namespace std;
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define m_p make_pair
#define P pair<int, int>
#define x first
#define y second
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x3f3f3f3f;

const LL mod = 998244353;
long long Pow(long long x, long long k) //大指数幂取模运算，x为底数，k为指数，计算x^K对P取模的值
{
    long long ret = 1;
    for (; k; k >>= 1, x = x * x % mod)
        if (k & 1)
            ret = ret * x % mod;
    return ret;
}
void change(LL &a, LL &b)
{
    for (LL i = 2; i <= min(a, b); i++)
    {
        while (a % i == 0 and b % i == 0)
            a /= i, b /= i;
    }
}
int main()
{
    IOS;
#ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt", "w", stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt", "r", stdin);
#endif

    LL A, B;

    int t;
    cin >> t;
    while (t--)
    {
        LL n, p, q;
        cin >> n >> p >> q;
        LL round;
        if(q!=100)
            round = (100 * n - 1) / (100 - q) + 1; //期望轮数
        else 
            round=n;
        A = 100 * n - q * (round - 1);
        B = 100;
        change(A, B);
        if (A % B == 0)
        {
            cout << Pow(A / B, 1) << endl;
        }
        else
        {
            cout << ((A % mod) * Pow(B, mod - 2)) % mod << endl;
        }
    }
    return 0;
}
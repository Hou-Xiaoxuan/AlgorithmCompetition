// By BLADEVIL
#include <cstdio>
#include <bits/stdc++.h>
#define maxn 110

using namespace std;

int n;
double x[maxn], y[maxn];
double p[maxn];

// 判断三点是否共线
bool judge(int i, int j, int k)
{
    return ((x[j] - x[i]) * (y[k] - y[i]) - (y[j] - y[i]) * (x[k] - x[i])) < 0;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    cin >> n;
    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                double q = p[i] * p[j];
                for (int k = 1; k <= n; k++)
                    if ((k != i) && (k != j) && (judge(i, j, k)))
                        q *= 1.0 - p[k];
                ans += q * (x[i] * y[j] - y[i] * x[j]);
            }
        }
    }
    ans /= 2.0;
    cout << setiosflags(ios::fixed) << setprecision(6);
    cout << ans + 1e-8 << endl;
    return 0;
}

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
        LL n;
        cin >> n;
        vector<LL> pre_sum(n + 1);
        vector<LL> a(n + 1);
        vector<bool> vis(n + 1);

        int err_times = 0;
        for (int i = 1; i < n; i++)    // n-1
        {
            cin >> pre_sum[i];
            a[i] = pre_sum[i] - pre_sum[i - 1];

            if (a[i] > n)
            {
                err_times++;
            }
            else
            {
                if (vis[a[i]] == true)
                {
                    err_times++;
                }
                vis[a[i]] = true;
            }
        }

        bool have_answer = true;
        bool conrect_presum = (pre_sum[n-1] == n * (n + 1) / 2ll);

        if (conrect_presum)
        {
            if (err_times == 1)
                have_answer = true;
            else
                have_answer = false;
        }
        else
        {
            if (err_times == 0)
                have_answer = true;
            else
                have_answer = false;
        }

        if (have_answer)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}
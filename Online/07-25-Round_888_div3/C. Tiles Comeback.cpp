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
        vector<int> a(n + 1);
        unordered_map<int, int> color_cnt;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            color_cnt[a[i]]++;
        }
        bool have_answer = true;
        do
        {
            if (color_cnt[a[1]] < k or color_cnt[a[n]] < k)
            {
                have_answer = false;
                break;
            }
            if (a[1] == a[n])    // yes
                break;

            // a[i] != a[n]
            int first_index = 0;
            int tmp = 0;
            for (int i = 1; i <= n; i++)
            {
                if (a[i] == a[1])
                    tmp++;

                if (tmp == k)
                {
                    first_index = i;
                    break;
                }
            }
            tmp = 0;
            int second_index = 0;
            for (int i = n; i >= 1; i--)
            {
                if (a[i] == a[n])
                    tmp++;

                if (tmp == k)
                {
                    second_index = i;
                    break;
                }
            }

            if (first_index > second_index)    // no
                have_answer = false;
        } while (false);
        if (have_answer)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
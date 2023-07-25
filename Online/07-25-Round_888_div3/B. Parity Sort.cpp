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
    freopen("in.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> odd, even;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2)
                odd.push_back(a[i]);
            else
                even.push_back(a[i]);
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        int oddi = 0, eveni = 0;

        bool have_answer = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)    // even
            {
                int num = lower_bound(odd.begin(), odd.end(), even[eveni]) - odd.begin();
                if (num != i - eveni)
                {
                    have_answer = false;
                    break;
                }
                eveni++;
            }
            else
            {
                int num = lower_bound(even.begin(), even.end(), odd[oddi]) - even.begin();
                if (num != i - oddi)
                {
                    have_answer = false;
                    break;
                }
                oddi++;
            }
        }

        if (have_answer)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}
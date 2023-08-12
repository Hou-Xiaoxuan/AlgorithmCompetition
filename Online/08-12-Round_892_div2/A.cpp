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
    //  freopen("out.txt","w",stdout);
    freopen("in.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int max_index = max_element(a.begin(), a.end()) - a.begin();
        int max_count = count(a.begin(), a.end(), a[max_index]);
        if (max_count == n)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << n - max_count << " " << max_count << endl;
            for (int i = 0; i < n; i++)
                if (a[i] != a[max_index])
                    cout << a[i] << " ";
            cout << endl;

            for (int i = 0; i < max_count; i++)
                cout << a[max_index] << " ";
            cout << endl;
        }
    }
    return 0;
}
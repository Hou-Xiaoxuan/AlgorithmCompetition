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
    size_t n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string u(n, '0');
    int tmp = 0;
    for(size_t i=0; i<n; i++)
        tmp += s[i] != t[i];
    if (tmp & 1)
        cout << "-1" << endl;
    else
    {
        int cnt[2] = {tmp / 2, tmp / 2};
        for (size_t i = 0; i < n; i++)
        {
            if (s[i] == t[i])
                u[i] = '0';
            else
            {
                if (cnt[0] > 0 and cnt[1] > 0)
                {
                    u[i] = '0';
                    if (s[i] == '0')
                        cnt[1]--;
                    else
                        cnt[0]--;
                }
                else if (cnt[0] > 0)    // 必须跟s相反
                {
                    u[i] = t[i];
                    cnt[0]--;
                }
                else if (cnt[1] > 0)    // 必须跟s相同
                {
                    u[i] = s[i];
                    cnt[1]--;
                }
            }
        }
        cout<<u<<endl;
    }
    return 0;
}

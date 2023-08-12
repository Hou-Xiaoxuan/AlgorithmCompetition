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
freopen("in.txt","r",stdin);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int tmp = -1;
            int num = 0;
            for (int j = 1; j <= n; j++)
            {
                if (j < i)
                {
                    num += j * j;
                    tmp = max(tmp, j * j);
                }
                else
                {
                    num += j * (n + i - j);
                    tmp = max(tmp, j * (n + i - j));
                }
            }
            ans = max(ans, num - tmp);
        }
        cout<<ans<<endl;
    }


    return 0;
}
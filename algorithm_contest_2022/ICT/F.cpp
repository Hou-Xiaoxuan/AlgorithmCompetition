/*
 * @Author: linxuan
 * @Date: 2022-07-19 22:13:26
 * @Description: file content
 * @FilePath: /Algorithm/algorithm_contest_2022/ICT/F.cpp
 */
#ifndef _USE_MATH_DEFINES
 #define _USE_MATH_DEFINES
#endif
#include <bits/stdc++.h>
#define IOS                   \
 ios::sync_with_stdio(false); \
 cin.tie(0);                  \
 cout.tie(0);
#define m_p make_pair
#define x   first
#define y   second
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
    // freopen("out.txt", "w", stdout);
    freopen("in.txt", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;
    LL sum = 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    auto check = [&](LL border) -> bool {
        LL cnt = 0, tmp = 0;
        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            if(a[i] > border) {
                flag = false;
                break;
            }
            if(tmp + a[i] > border) {
                cnt++;
                tmp = a[i];
            } else {
                tmp += a[i];
            }
         }
        if(tmp > 0) cnt++;
        return cnt<=m and flag;
    };

    LL ans = -1;
    LL l=1, r = sum;
    while(l<=r)
    {
        LL mid = (l + r)/2;
        if(check(mid))
        {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}


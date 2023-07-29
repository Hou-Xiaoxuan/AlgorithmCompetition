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
        /* code */
        int n, k;
        cin >> n >> k;
        struct Monsters {
            /* data */
            int health;
            int index;
            bool operator<(const Monsters &a) const
            {
                if (health != a.health)
                    return health < a.health;
                else
                    return index > a.index;
            }
        };
        priority_queue<Monsters> que;
        for (int i = 1; i <= n; i++)
        {
            Monsters x;
            cin >> x.health;
            x.health %= k;
            if (x.health == 0)
                x.health = k;
            x.index = i;
            que.push(x);
        }
        while (not que.empty())
        {
            auto cur = que.top();
            que.pop();
            if (cur.health <= k)
            {
                if (que.empty())
                    cout << cur.index << endl;
                else
                    cout << cur.index << ' ';
            }
            else
            {
                cur.health -= k;
                que.push(cur);
            }
        }
    }

    return 0;
}
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
        queue<pair<int, LL>> que;    // i, diff cost
        vector<LL> buy_cost(n + 1, 0);
        vector<LL> combin_cost(n + 1, 0);
        vector<vector<int>> target_point(n + 1);
        vector<vector<int>> from_point(n + 1);
        vector<int> du(n + 1, 0);

        for (int i = 1; i <= n; i++)
            cin >> buy_cost[i];

        for (int i = 1; i <= k; i++)
        {
            int tmp;
            cin >> tmp;
            buy_cost[tmp] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            int m;
            cin >> m;
            du[i] = m;
            if (m == 0)
            {
                combin_cost[i] = inf;    // 不可合成
            }
            else
            {
                LL cost_i = 0;
                for (int j = 0; j < m; j++)
                {
                    int tmp;
                    cin >> tmp;    // i need tmp
                    from_point[i].push_back(tmp);
                    target_point[tmp].push_back(i);
                    cost_i += buy_cost[tmp];
                }
                combin_cost[i] = cost_i;
            }
            if (buy_cost[i] == 0 or du[i] == 0)
            {
                du[i] = 0;
                que.push({i, 0});    // 无用节点
            }
        }

        while (not que.empty())
        {
            auto st = que.front();
            que.pop();
            int cur = st.x;
            LL diff = st.y;

            for (auto target : target_point[cur])
            {
                du[target]--;
                combin_cost[target] -= diff;
                if (du[target] == 0)
                {
                    que.emplace(target, max(0ll, buy_cost[target] - combin_cost[target]));
                }
            }
        }


        for (int i = 1; i <= n; i++)
            cout << min(combin_cost[i], buy_cost[i]) << " ";
        cout << endl;
    }


    return 0;
}
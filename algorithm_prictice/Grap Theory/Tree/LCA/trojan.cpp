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
/** trojan算法的离线LCA问题
 * 算法流程：在dfs过程中，不断标记访问过的节点，更新并查集fa[i]
 *      特殊的更新策略：在dfs过程中，访问完u的所有子节点后，再更新fa[u]。
 *          如果访问到一个子节点v，发现存在query(v,v')，且v'已经被访问标记过了，则答案lca(v, v')为fa[v']
 *          note: 因为v、v'的遍历顺序未知，因此query存双向边
 *  证明：
 * 如果v'与v在一颗子树上，由于v'已经回溯，v'是v的孩子，则fa[v']还没有更新，v'刚刚被访问且回溯，fa[v'] = v。
 * 如果v'与v在两棵字数上，则说明v'所在的子树已经遍历完成，且现在他的祖先u也是v的祖先。
 *  反证：如果u不是最近的公共祖先，则说明存在u的子节点u'是v和v'的公共祖先。那fa[v] =
 *  u说明u'已经回溯了，但是此时还在u'的子树v上，与u'是公共祖先矛盾。
 */
// XXX 存在奇妙bug，本地会炸，提交能过
int main()
{
    IOS;
#ifdef _DEBUG
    freopen("P3379_13.in", "r", stdin);
#endif

    int n, m, root;
    cin >> n >> m >> root;
    vector<vector<int>> graph(n + 1);    // 存图
    struct ans_result {
        int v, id;
    };                                          // query
    vector<vector<ans_result>> query(n + 1);    // 存query，双向边
    vector<int> query_ans(m + 1);               // 结果
    vector<bool> vis(n + 1, false);             // 不是stl、不是vector，不是bool......

    /* 并查集 */
    vector<int> fa(n + 1);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    function<int(int)> get_father = [&get_father, &fa](int x) -> int {
        return fa[x] == x ? x : fa[x] = get_father(fa[x]);
    };
    function<void(int, int)> merge = [&get_father, &fa](int x, int y) {
        assert(get_father(y) < fa.size());
        fa[get_father(y)] = get_father(x);
    };

    // 读数据
    for (int i = 1; i <= n - 1; i++)    // n-1条边
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        query[u].push_back({v, i});
        query[v].push_back({u, i});
    }

    // tarjon dfs
    function<void(int, int)> dfs = [&](int u, int father) -> void {
        // 访问u的子节点
        for (auto v : graph[u])
        {
            if (v == father)
                continue;
            vis[v] = true; // XXX 这里需要先标记再dfs，暂时不能理解。洛谷模板没有这样写
            dfs(v, u);
            merge(u, v);
        }

        // 访问完u的子节点后，更新fa[u]
        for (auto [v_, id] : query[u])
        {
            if (v_ == father)
                continue;
            if (vis[v_] == true)
                query_ans[id] = get_father(v_);
        }
    };

    // 输出答案
    dfs(root, root);
    for (int i = 1; i <= m; i++){
        cout << query_ans[i] << endl;
    }
    return 0;
}
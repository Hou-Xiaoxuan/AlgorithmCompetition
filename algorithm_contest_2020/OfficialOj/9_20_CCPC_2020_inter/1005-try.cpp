#include <bits/stdc++.h>

using namespace std;

const int N = 200001;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    unordered_map<int, int> sg;
    unordered_map<int, int> vis;
    vector<int> p(N);
    vis[1] = 1;

    int mk = 0;

    while (T--)
    {
        int n;
        cin >> n;

        vector<int> l(n);//目前这道题目的长度
        for (int i = 0; i < n; ++i)
        {
            cin >> l[i];
        }

        // 打表函数：
        function<void(int)> dfs = [&](int n) 
        {
            if (vis.count(n))
            {
                return;
            }
            vis[n] = 1;
            vector<int> tmp;//存放子状态的sg值
            for (int i = 1; i * i <= n; ++i)
            {
                if (n % i == 0)
                {
                    //分解为i个j
                    int j = n / i;
                    if (i != 1)
                    {
                        if (!(i & 1))//i是偶数,偶数项的异或一定是0
                        {
                            tmp.emplace_back(0);
                        }
                        else
                        {
                            dfs(j);
                            tmp.emplace_back(sg[j]);//奇数项j的异或就是sg[j]
                        }
                    }
                    //考虑另一个因数j，分解为j个i
                    if (j != 1 && i != j)
                    {
                        if (!(j & 1))//偶数项
                        {
                            tmp.emplace_back(0);
                        }
                        else
                        {
                            dfs(i);
                            tmp.emplace_back(sg[i]);
                        }
                    }
                }
            }
            // 目的大概应该是找不在tmp里面的最小数
            // 引入mk的目的是为了确定那些是使用一个数组而确定那些数字是本轮被使用过的
            mk += 1;
            for (int i : tmp)
            {
                if (i < N)
                {
                    p[i] = mk;
                }
            }
            for (int i = 0;; ++i)
            {
                if (p[i] != mk)
                {
                    sg[n] = i;
                    break;
                }
            }
        };

        int sum = 0;
        for (int x : l)
        {
            dfs(x);
            sum ^= sg[x];
        }

        if (sum)
        {
            cout << 'W' << '\n';
        }
        else
        {
            cout << 'L' << '\n';
        }
    }
    return 0;
}
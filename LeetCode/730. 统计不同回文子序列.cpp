/*
 * @Author: linxuan
 * @Date: 2022-06-11 01:55:26
 * @Description: DP真神奇。摆烂直接看题解了
 * @FilePath: /Algorithm/LeetCode/730. 统计不同回文子序列.cpp
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
class Solution
{
public:
    static const LL mod = 1000000007;
    int countPalindromicSubsequences(string s)
    {
        int n = s.size();
        vector<vector<LL>> dp(n, vector<LL>(n, 0));
        vector<vector<int>> cnt(4, vector<int>(n + 1, 0));    // 不同字母的前缀和(前k个字母中的数量)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 4; j++)
                cnt[j][i + 1] = cnt[j][i] + (s[i] - 'a' == j);
        }
        auto get_cnt = [&](int l, int r, char ch) {    // 返回下表l-r区间内ch的个数
            return cnt[ch - 'a'][r + 1] - cnt[ch - 'a'][l];
        };
        for (int len = 1; len <= n; len++)
        {
            for (int l = 0; l + len - 1 < n; l++)
            {
                int r = l + len - 1;
                if (l == r)
                {
                    dp[l][r] = 1;
                    continue;
                }
                else
                {
                    // s[l]==s[r]，则l+1~r-1范围内的回文串两侧加上相同字母形成新的回文
                    if (s[l] == s[r])
                    {
                        int cnt = get_cnt(l + 1, r - 1, s[l]);
                        if (cnt > 1)
                        {
                            int l_last = l + 1, r_last = r - 1;    // 回文串的左右两侧的ch字符位置
                            while (l_last <= r_last && s[l_last] != s[l])
                                l_last++;
                            while (l_last <= r_last && s[r_last] != s[r])
                                r_last--;
                            assert(l_last <= r_last and r_last < r and l_last > l);
                            dp[l][r] = 2 * dp[l + 1][r - 1] - dp[l_last + 1][r_last - 1];
                        }
                        else
                        {
                            // 有0/1个相同字母，那么只有单字符的重复可能
                            dp[l][r] = 2 * dp[l + 1][r - 1] + (cnt == 0 ? 2 : 1);
                        }
                    }
                    // 只能分别考虑l~r-1、l+1~r、l+1~r-1两个范围
                    else
                    {
                        dp[l][r] = dp[l][r - 1] + dp[l + 1][r] - dp[l + 1][r - 1];
                    }
                }
                dp[l][r] = (dp[l][r] + mod) % mod;
            }
        }

        return dp[0][n - 1];
    }
};
int main()
{
    string s;
    s.reserve(1005);
    cin >> s;

    Solution solve;
    cout << solve.countPalindromicSubsequences(s) << endl;
    return 0;
}

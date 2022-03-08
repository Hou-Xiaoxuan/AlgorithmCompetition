/*
 * @Author: LinXuan
 * @Date: 2021-08-24 11:45:03
 * @Description: 
 * @LastEditors: LinXuan
 * @LastEditTime: 2021-08-25 20:31:58
 * @FilePath: /Algorithm/LeetCode/10.正则表达式匹配.cpp
 */
/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 * 不会做，太菜了
 * 看题解有两种做法，递归和DP。时间复杂度都应该差不多吧
 * dp好难啊！！
 */

// @lc code=start
# ifndef _USE_MATH_DEFINES
# define _USE_MATH_DEFINES
# endif
# include<bits/stdc++.h>
# define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
# define  m_p make_pair
# define x first
# define y second 
using namespace std;
using LL=long long;
using ULL=unsigned long long;
using LD=long double;
using P=pair<int,int>;
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;

class Solution {
public:
    bool isMatch(string s, string p)
    {   s = " " + s;
        p = " " + p;
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        
        // 需要考虑"" 匹配 "a*"是true
        for(size_t i = 0; i < s.size(); i++)
            for(size_t j = 1; j < p.size(); j++)
            {
                // dp[i][j] == s[i] <=> p[j]
                if(p[j] != '*')
                {
                    if(i!=0 and (s[i] == p[j] or p[j] == '.'))
                        dp[i][j] = dp[i-1][j-1];
                    else 
                        dp[i][j] = false;
                }
                else
                {
                    if(i!=0 and (s[i] == p[j-1] or p[j-1] == '.'))
                        // 匹配的话，可以匹配这个字符，或者抛弃这个正则字符
                        // 有两种转移方式
                        dp[i][j] = dp[i-1][j] | dp[i][j-2];
                    else
                        // 不匹配的话，抛弃这个正则字符，继续匹配
                        // 从dp[i-1][j-2]而来的话，就是不匹配s[i]和p[i-1]，此时可以从s[i-1]和p[i-2]的匹配中转移过来
                        dp[i][j] = dp[i][j-2];
                }
            }
        return dp[s.size()-1][p.size()-1];
    }
};
// @lc code=end
# ifdef _DEBUG
int main(int argc, char const *argv[])
{
    string s = "aa";
    string p = ".*";
    Solution test;
    test.isMatch(s, p);
    return 0;
}

# endif


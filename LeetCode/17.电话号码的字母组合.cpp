/*
 * @Author: LinXuan
 * @Date: 2021-08-28 22:07:12
 * @Description: 
 * @LastEditors: LinXuan
 * @LastEditTime: 2021-08-28 22:18:51
 * @FilePath: /Algorithm/LeetCode/17.电话号码的字母组合.cpp
 */
/*
 * @lc app=leetcode.cn id=17 lang=cpp
 * [17] 电话号码的字母组合
 * dfs遍历
 */
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

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ma= {
            "",
            "!@#",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        vector<string> ans;
        function<void(string&, size_t)> f; // 为了使用递归，必须先声明在定义。
        f = [&](string &s, size_t k) -> void
        {
            if(k >= digits.size()){
                if(s != "")
                    ans.push_back(s);
                return;
            }
            for(char ch:ma[digits[k] - '0']){
                s.push_back(ch);
                f(s, k+1);
                s.pop_back();
            }
        };

        string tmp = "";
        f(tmp, 0ull);
        return ans;
    }
};
// @lc code=end
# ifdef _DEBUG
int main(int argc, char const *argv[])
{
    string digits = "23";
    Solution test;
    test.letterCombinations(digits);
    return 0;
}

# endif

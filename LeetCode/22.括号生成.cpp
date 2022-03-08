/*
 * @Author: LinXuan
 * @Date: 2021-08-30 13:41:40
 * @Description: 
 * @LastEditors: LinXuan
 * @LastEditTime: 2021-08-30 14:22:31
 * @FilePath: /Algorithm/LeetCode/22.括号生成.cpp
 */
/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 * DP吧。关键在于
 * 1. 此前的前n-1对括号分解为（a）b的形式，a，b都是合法的括号序列
 * 2. 由于合法的括号序列不会与其他的括号对应了，因此a，b的不同不会造成重复*
 * 失策了，需要的不是种类数目而是枚举结果
 * 
 * 还可以直接dfp、遍历等方法
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
    vector<string> generateParenthesis(int n)
    {
        // Wrong 不是计数问题
        // vector<int> f(n+1, 0);
        // f[0] = f[1] = 1;
        // for(int i=2; i<=n; i++)
        // {
        //     for(int j=1; j<=i/2; j++)
        //     {
        //         f[i] += f[j]*f[i-j];
        //     }
        // }
        // return f[n];

        // AC dp
        // vector<vector<string>> f(n+1, vector<string>());
        // f[0] = vector<string>({""});
        // f[1] = vector<string>({"()"});
        // for(int i=2; i<=n; i++)
        // {
        //     for(int j=0; j<=i - 1; j++)
        //     {
        //         for(string left: f[j])
        //             for(string right: f[i - 1 - j])
        //                 f[i].push_back("(" + left + ")" + right);
        //     }
        // }
        // return f[n];

        // AC dfs剪枝，枚举所有情况。通过括号的数量剪枝
        // vector<string> ans;
        // function<void(string&, int, int)> f;
        // f = [&ans, &f](string& str, int left, int right)
        // {
        //     if(left == 0 and right == 0){
        //         ans.push_back(str);
        //         return;
        //     }

        //     if(left == right){
        //         str.push_back('(');
        //         f(str, left-1, right);
        //         str.pop_back();
        //     }
        //     else if(left < right)
        //     {
        //         if(left > 0){
        //             str.push_back('(');
        //             f(str, left-1, right);
        //             str.pop_back();
        //         }
        //         str.push_back(')');
        //         f(str, left, right-1);
        //         str.pop_back();
        //     }
        // };
        // string str = "";
        // f(str, n, n);
        // return ans;
    }
};
// @lc code=end
# ifdef _DEBUG
int main(int argc, char const *argv[])
{
    freopen("out.txt", "w", stdout);
    Solution test;
    test.generateParenthesis(8);
    return 0;
}

# endif


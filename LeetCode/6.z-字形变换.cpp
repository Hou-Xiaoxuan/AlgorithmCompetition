/*
 * @Author: LinXuan
 * @Date: 2021-08-27 10:09:47
 * @Description: 
 * @LastEditors: linxuan
 * @LastEditTime: 2021-08-28 09:54:07
 * @FilePath: /Algorithm/LeetCode/6.z-字形变换.cpp
 */
/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 * 细节一大堆
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
    string convert(string s, int numRows)
    {
        string ans;
        if(numRows == 1)
            return s;
        for(int i=1; i<=numRows; i++) // 第几行
        {
            for(int base = 0; base < s.size(); base += 2*numRows-2) // 第几轮
            {
                int index = i;
                if(base + index - 1 <s.size())
                    ans.push_back(s[base + index-1]);
                index = 2 * numRows - i;
                if(index > numRows and index < 2*numRows - 1 and base + index - 1 < s.size())
                    ans.push_back(s[base + index-1]);
            }
        }
        return ans;
    }
};
# ifdef _DEBUG
int main(int argc, char const *argv[])
{
    string s = "PAYPALISHIRING";
    Solution test;
    cout<<test.convert(s, 3)<<endl;
    return 0;
}

# endif
// @lc code=end


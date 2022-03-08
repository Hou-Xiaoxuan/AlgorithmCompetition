/*
 * @Author: linxuan
 * @Date: 2021-08-28 21:08:11
 * @Description: file conte
 * @LastEditors: LinXuan
 * @LastEditTime: 2021-08-28 22:00:16
 * @FilePath: /Algorithm/LeetCode/14.最长公共前缀.cpp
 */
/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 * 签到模拟
 */

// @lc code=start
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define x first
#define y second 
using namespace std;
using LL=long long;
using ULL=unsigned long long;
using LD=long double;
using P=pair<int,int>;
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string ans;
        bool flag = true;
        for(size_t i = 0; flag == true; i++)
        {
            flag = true;
            char ch = ' ';
            for(auto &s: strs)
            {
                if(i < s.size())
                {
                    if(ch == ' ') ch = s[i];
                    if(ch != s[i]){
                        flag = false;
                        break;
                    }
                }
                else {
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(ch);
        }
        return ans;
    }
};
// @lc code=end
# ifdef _DEBUG
int main(int argc, char const *argv[])
{
    vector<string> strs = {
        "flower","flow","flight"
    };
    for (string s : strs){
        cout<<s<<endl;
    }
    Solution test;
    test.longestCommonPrefix(strs);
    return 0;
}

# endif

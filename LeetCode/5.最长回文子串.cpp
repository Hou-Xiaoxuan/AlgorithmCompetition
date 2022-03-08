/*
 * @Author: linxuan
 * @Date: 2021-08-20 00:44:26
 * @Description: file contenti
 * @LastEditors: linxuan
 * @LastEditTime: 2021-08-20 10:26:42
 * @FilePath: /Algorithm/LeetCode/5.最长回文子串.cpp
 */
/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 * 马拉车问题模 板题
 * AC
 */
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

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string str;
        str.assign((s.size()*2 - 1), '#');
        for(size_t i = 0; i<s.size(); i++) {
            str[i*2] = s[i];
        }
    // cout<<"debug, "<<str<<endl;
        vector<int> pArr(str.length(), 0); // pArr[i]回文半径长度包括自身
        int C = -1, R = -1; // center, right
        for(int i = 0; i<str.length(); i++)
        {
            // 1. 思维逻辑
            // if(i >= R) {
            //     // 直接暴力匹配
            // }
            // else if(i + pArr[2*C - i] < R) {
            //     // 在内部，直接得到结果
            //     pArr[i] = pArr[2*C - i];
            // }
            // else if(i + pArr[2*C - i] == R) {
            //     // 对称边界为R，直接得到结果
            //     pArr[i] = R - i;
            // }
            // else if(i + pArr[2*C - i > R]) {
            //     // 有最小值，仍需直接暴力匹配
            //     pArr[i] = R - i;
            // }

            // 2. 优化
            if(i <  R) // 初始化为1
                pArr[i] = min(pArr[2*C - i], R - i);

            // 执行暴力匹配
            while(i - pArr[i] >= 0 and i + pArr[i] < str.size())
            {
                if(str[i - pArr[i]] == str[i + pArr[i]]) {
                    pArr[i] ++;
                }
                else break;
            }

            // 更新边界
            if(i + pArr[i] > R) {
                R = i + pArr[i];
                C = i;
            }
        }
    
        // 返回最长回文串
        int c, len = -1;
        for(size_t i = 0; i< pArr.size(); i++)
        {
            if(str[i] == '#' and pArr[i] >= len and pArr[i]!=1) {
                c = i;
                len = pArr[i];
            }
            else if(pArr[i] > len) {
                c = i;
                len = pArr[i];
            }
        }
        string ans;
        for(int i = c - len + 1; i <= c + len - 1; i++)
            if(str[i] != '#')
                ans.push_back(str[i]);
        return ans;
    }
};
// @lc code=end

# ifdef _DEBUG
int main(int argc, char const *argv[])
{
    string s = "aab";
    Solution test;
    cout<<test.longestPalindrome(s)<<endl;
    return 0;
}

#endif

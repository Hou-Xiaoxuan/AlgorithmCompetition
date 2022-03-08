/*
 * @Author: linxuan
 * @Date: 2021-08-28 09:57:21
 * @Description: file content
 * @LastEditors: linxuan
 * @LastEditTime: 2021-08-28 21:06:31
 * @FilePath: /Algorithm/LeetCode/12.整数转罗马数字.cpp
 */
/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 * 规则：合法字符组 从大到小组合
 * 还能这么玩啊
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
    string intToRoman(int num)
    {
        static unordered_map<int, string> ma = {
            {1, "I"},
            {2, "II"},
            {3, "III"},
            {4,"IV"},
            {5, "V"},
            {6, "VI"},
            {7, "VII"},
            {8, "VIII"},
            {9, "IX"},
            {10, "X"},
            {20, "XX"},
            {30, "XXX"},
            {40, "XL"},
            {50, "L"},
            {60, "LX"},
            {70, "LXX"},
            {80, "LXXX"},
            {90, "XC"},
            {100, "C"},
            {200, "CC"},
            {300, "CCC"},
            {400, "CD"},
            {500, "D"},
            {600, "DC"},
            {700, "DCC"},
            {800, "DCCC"},
            {900, "CM"},
            {1000, "M"},
        };
        string ans;
        while(num>0)
        {
            if(num > 1000) {
                ans += ma[1000];
                num -= 1000;
            }
            else if(num > 100) {
                int tmp = (num/100)*100;
                ans += ma[tmp];
                num -= tmp;
            }
            else if(num > 10) {
                int tmp = (num/10)*10;
                ans += ma[tmp];
                num -= tmp;
            }
            else {
                ans += ma[num];
                num = 0;
            }
        }
        return ans;
    }
};
// @lc code=end


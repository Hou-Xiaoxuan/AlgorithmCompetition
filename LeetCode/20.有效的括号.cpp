/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 * stack 签到
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
    bool isValid(string s)
    {
        bool ans = true;
        stack<char> sta;
        for(char ch : s)
        {
            if(ch == '(' or ch == '[' or ch == '{')
                sta.push(ch);
            else
            {
                if(sta.empty()) {
                    ans = false;
                    break;
                }
                char match = sta.top();
                sta.pop();
                bool check =  false;
                check |= ch == ')' and match == '(';
                check |= ch == ']' and match == '[';
                check |= ch == '}' and match == '{';
                if(check == false) {
                    ans = false;
                    break;
                }
            }
            
        }
        if(sta.empty() == false)
            ans = false;
        return ans;
    }
};
// @lc code=end


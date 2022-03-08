/*
 * @Author: linxuan
 * @Date: 2021-08-20 10:30:09
 * @Description: file content
 * @LastEditors: linxuan
 * @LastEditTime: 2021-08-20 11:25:27
 * @FilePath: /Algorithm/LeetCode/8.字符串转换整数-atoi.cpp
 */
/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 * 小模拟
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
    int myAtoi(string s)
    {
        using LL = long long;
        LL flag = 0;
        LL ans = 0;
        for(char ch : s)
        {   
            if(ch == ' ' and flag == 0) continue;
            else if(ch == '-' and flag == 0) flag = -1;
            else if(ch == '+' and flag == 0) flag = 1;
            else if(ch < '0' or ch > '9') {
                break;
            }
            else{
                if(flag == 0) flag = 1;
                ans = ans * 10 + (ch - '0');
            }
            if(flag == -1 and ans > (1ll<<31)){
                ans = 1ll<<31;
                break;
            } 
            else if(flag == 1 and ans > (1ll << 31) - 1) {
                ans = (1ll<<31) - 1;
                break;
            }
        }
        ans *= flag;
        return int(ans);
    }
};
// @lc code=end

# ifdef _DEBUG
int main(int argc, char const *argv[])
{
    Solution test;
    cout<<test.myAtoi("-2147483648")<<endl;
    return 0;
}

#endif

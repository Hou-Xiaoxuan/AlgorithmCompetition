/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 * 模拟 AC
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
    int romanToInt(string s) {
        unordered_map<char, int> value{{'I', 1}, {'V', 5}, {'X', 10}, 
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        // queue<int> que;
        int ans = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(i == s.length() - 1){
                // que.push(value[s[i]]);
                ans += value[s[i]];
            }
            else
            {
                if(value[s[i]] < value[s[i+1]]) {
                    // que.push(value[s[i+1]] - value[s[i]]);
                    ans += value[s[i+1]] - value[s[i]];
                    i++;
                }
                else {
                    // que.push(value[s[i]]);
                    ans += value[s[i]];
                }
            }
        }
        return ans;
    }
};
// @lc code=end
#ifdef _DEBUG
int main()
{
    IOS;
    string s = "MCMXCIV";
    Solution test;
    cout<<test.romanToInt(s)<<endl;  
    return 0;
}
#endif


/*
 * @Author: LinXuan
 * @Date: 2021-08-27 09:55:07
 * @Description: 
 * @LastEditors: LinXuan
 * @LastEditTime: 2021-08-27 10:07:28
 * @FilePath: /Algorithm/LeetCode/3.无重复字符的最长子串.cpp
 */
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 * queue遍历同时进行计数统计O(n)
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
    int lengthOfLongestSubstring(string s)
    {
        vector<int> cnt(129, 0); // ascii 计数
        queue<char> que;
        size_t ans = 0;
        for(char ch: s)
        {
            if(cnt[int(ch)]>0) 
            {
                ans = max(ans, que.size());
                while(que.empty()==false and cnt[int(ch)]>0) {
                    cnt[que.front()]-- ;
                    que.pop();
                }
            }
            que.push(ch);
            cnt[int(ch)]++;
        }
        ans = max(ans, que.size());
        return ans;
    }
};
# ifdef _DEBUG
int main(int argc, char const *argv[])
{
    string s = "abccbacbb";
    Solution test = Solution();
    test.lengthOfLongestSubstring(s);
    return 0;
}

# endif
// @lc code=end


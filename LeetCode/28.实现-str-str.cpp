/*
 * @Author: LinXuan
 * @Date: 2021-09-01 22:01:55
 * @Description: 
 * @LastEditors: LinXuan
 * @LastEditTime: 2021-09-01 22:34:40
 * @FilePath: /Algorithm/LeetCode/28.实现-str-str.cpp
 */
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
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
    int strStr(string haystack, string needle)
    {
        // kmp
        if(needle.empty()) return 0;

        //kmp[i]的值代表当前位置可以和多少位的前缀匹配
        vector<int> kmp(needle.size(), 0);
        int j = 0; // 当前匹配长度
        for(int i=1; i<needle.size(); i++)
        {
            while(j>0 and needle[j] != needle[i])
                j = kmp[j - 1];

            if(needle[j] == needle[i]) j++;
            kmp[i] = j;
        }

        j = 0;
        for(int i=0; i<haystack.size(); i++)
        {
            while(j>0 and haystack[i] != needle[j])
                j = kmp[j - 1];
            if(haystack[i] == needle[j]) j++;

            if(j == needle.size()){
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
};
// @lc code=end
# ifdef _DEBUG
int main(int argc, char const *argv[])
{
    string s = "hello";
    string p = "ll";
    Solution test;
    test.strStr(s, p);
    return 0;
}

# endif

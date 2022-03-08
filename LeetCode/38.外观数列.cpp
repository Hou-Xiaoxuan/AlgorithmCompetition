/*
 * @Author: LinXuan
 * @Date: 2021-09-07 14:02:42
 * @Description: 
 * @LastEditors: LinXuan
 * @LastEditTime: 2021-09-07 14:52:43
 * @FilePath: /Algorithm/LeetCode/38.外观数列.cpp
 */
/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
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
    string countAndSay(int n)
    {
        static vector<string> ans;
        static function<string(const string&)> get = [](const string &s) -> string{
            string rt;
            char ch  = ' ';
            int cnt = 0;
            for(char ite : s)
            {
                if(ch == ite){
                    cnt ++;
                }
                else
                {
                    if(cnt > 0){
                        rt += to_string(cnt);
                        rt += ch;
                    }
                    ch = ite;
                    cnt = 1;
                }
            }
            if(cnt > 0){
                rt += to_string(cnt);
                rt += ch;
            }
            return rt;
        };
        if(ans.size() < n + 1)
        {
            // 初始化
            ans.assign(n+1, "");
            ans[1] = "1";
            for(size_t i = 2; i<=n; i++)
            {
                ans[i] = get(ans[i-1]);
            }
        }
        return ans[n];
    }
};
// @lc code=end
# ifdef _DEBUG
int main(int argc, char const *argv[])
{
    Solution test;
    test.countAndSay(5);
    return 0;
}

# endif


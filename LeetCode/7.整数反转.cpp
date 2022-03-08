/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
# include <string>
# include <iostream>
# include <algorithm>
using namespace std;
// @lc code=start
class Solution {
    string maxi = "2147483648"; // 最大的正整数
public:
    int reverse(int x) {
        string val = to_string(x);
        if(x < 0) {
            val = val.substr(1, val.size() - 1);
        }
        std::reverse(val.begin(), val.end());

        // 不足
        if(val.size() == maxi.size())
        {
            for(size_t i=0; i<maxi.size(); i++) {
                if(val[i] < maxi[i]){
                    break;
                }
                else if(val[i] == maxi[i]){
                    continue;
                }
                else {
                    return 0;
                }
            }
            if(x > 0 and val == maxi){
                return 0;
            }
        }
        return stoi(val)*(x<0?-1:1);
    }
};
// @lc code=end

int main()
{
    Solution sol;
    cout<<sol.reverse(-2147483412)<<endl;
}

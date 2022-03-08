/*
 * @Author: linxuan
 * @Date: 2021-08-22 08:43:54
 * @Description: file content   
 * @LastEditors: linxuan
 * @LastEditTime: 2021-08-22 09:58:47
 * @FilePath: /Algorithm/LeetCode/15.三数之和.cpp
 */
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
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

class MySolution {
    // 卡常，非标程,n^2*log(n)*3
public:
    int hash_vec(vector<int> tmp)
    {
        static hash<string> hash_str;
        string s;
        for(int val: tmp){
            s += (to_string(val) + "#");
        }
        return hash_str(s);
    }
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        hash<int> ha;
        vector<vector<int>> ans;
        unordered_map<int, bool> have;
        if(nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++)
        {
            int a = nums[i];
            if(i !=0  and nums[i] == nums[i - 1]){ // T了，剪枝
                continue;
            }
            for(int j=i+1; j<nums.size(); j++)
            {
                if( j != i+1 and nums[j] == nums[j - 1]){ // T了，剪枝
                    continue;
                }
                int b = nums[j];
                int k = lower_bound(nums.begin() + j + 1, nums.end(), -(a + b)) - nums.begin();
                if(k == nums.size()) continue; // 没有找到

                // 参考标程，这里已经不需要使用hash盘重了，两次剪枝确保了(a, b)不重复
                if(nums[k] + a + b == 0)
                {
                    // // hash去重
                    vector<int> tmp = {a, b, nums[k]};
                    int hash_tmp = this->hash_vec(tmp);
                    if(have[hash_tmp] == false) {
                        have[hash_tmp] = true;
                        ans.push_back(tmp);
                    }
                }
                
            }
        }
        return ans;
    }
};


class Solution {
    // 标程：双指针优化到n^2
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 保证a <=b <=c, 且(a,b)不重复即可
        // 通过双指针枚举a, b,同时使用一样的剪枝方法保证不重复，c从右往左枚举即可
        // 使用双指针遍历替代后两重循环，优化成O(n)
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(size_t first = 0; first < nums.size(); first++)
        {
            if(first > 0 and nums[first] == nums[first - 1]) continue;
            size_t third = nums.size() - 1;
            for(size_t second = first + 1; second < nums.size(); second++)
            {
                if(second > first + 1 and nums[second] == nums[second - 1]) continue;
                // 精髓：使用双指针
                while (third > second and nums[first] + nums[second] + nums[third] > 0){
                    third--;
                }
                if(third == second)
                    break;
                if(nums[first] + nums[second] + nums[third] == 0)
                    ans.push_back(vector<int>{nums[first], nums[second], nums[third]});
            }

        }
        return ans;
    }
};

// @lc code=end
#ifdef _DEBUG
int main(int argc, char const *argv[])
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution test;
    test.threeSum(nums);
    return 0;
}

#endif


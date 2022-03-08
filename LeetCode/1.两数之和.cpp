/*
 * @Author: LinXuan
 * @Date: 2021-08-16 09:52:37
 * @Description: 
 * @LastEditors: LinXuan
 * @LastEditTime: 2021-08-16 10:52:02
 * @FilePath: /Algorithm/LeetCode/1.两数之和.cpp
 */
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <bits/stdc++.h>
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
// AC
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ma;
        // n log(n)
        for(int i=0; i<nums.size(); i++){
            ma[nums[i]] = i;
        }
        vector<int> ans;
        for(auto ite: ma)
        {
            if(ite.first*2 == target) continue;
            if(ma.count(target - ite.first)>0){
                ans.push_back(ite.second);
                ans.push_back(ma[target - ite.first]);
                break;
            }
        }
        // 懒……特判解决吧
        // 说明答案是连个相同的数
        for(int i=0; i<nums.size() and ans.size()!=2; i++){
            if(nums[i] == target/2) ans.push_back(i);
        }
        
        if(ans[0] > ans[1]) swap(ans[0], ans[1]);
        return ans;
    }
};
// @lc code=end

// int main()
// {
//     IOS;
//     vector<int> nums{3,2,3};
//     int target = 6;
//     Solution test;
//     auto ans = test.twoSum(nums, target);
//     cout<<ans[0]<<" "<<ans[1]<<endl;
//     return 0;
// }

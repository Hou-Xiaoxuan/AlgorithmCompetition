/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 * 重要信息：原数组有序。那么就可以连续的跳过重复项。同时对已经写入的元素进行计数。
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
    int removeDuplicates(vector<int>& nums) {
        size_t l = 0, r = 0;
        while(r < nums.size()) {
            nums[l] = nums[r];
            while(r < nums.size() and nums[l] == nums[r]) r++;
            l++;
        }
        return l;
    }
};
// @lc code=end


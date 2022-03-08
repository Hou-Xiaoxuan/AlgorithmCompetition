/*
 * @Author: LinXuan
 * @Date: 2021-08-17 01:11:22
 * @Description: 
 * @LastEditors: linxuan
 * @LastEditTime: 2021-08-20 00:43:09
 * @FilePath: /Algorithm/LeetCode/4.寻找两个正序数组的中位数.cpp
 */
/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */
// 很经典的维护两个堆的题目
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

class Solution_one {
    // 没有读懂题目……给定的连个数组都是有序的，根本不需要维护两个堆
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> left; // 默认大根堆
        priority_queue<int, vector<int>, greater<int>> right;
        // 处理nums1
        for(int val : nums1)
        {
            if(left.empty() or val < left.top()) left.push(val);
            else right.push(val);
            while(left.size()> right.size() + 1){
                right.push(left.top());
                left.pop();
            }
            while(right.size() > left.size()) {
                left.push(right.top());
                right.pop();
            }
        }
        // 处理nums2
        for(int val : nums2)
        {
            if(left.empty() or val < left.top()) left.push(val);
            else right.push(val);
            while(left.size()> right.size() + 1){
                right.push(left.top());
                left.pop();
            }
            while(right.size() > left.size()) {
                left.push(right.top());
                right.pop();
            }
        }
        double ans = 0.0;
        if(left.size() > right.size()) ans = left.top();
        else ans = (left.top() + right.top()) / 2.0;
        return ans;
    }
};
class Solution{
    // 标程解法：类似二分的手法，对比两个有序数组的k/2-1处的值进行比对
public:

    int findKValue(vector<int>& nums1, vector<int>& nums2, int k)
    {
        // k不是角标，是第k大的数
        int n = nums1.size(), m = nums2.size();
        int index1 = 0, index2 = 0;
        while(true)
        {
            if(index1 == n) {
                // nums 没有元素了
                return nums2[index2 + k - 1];
            }
            else if(index2 == m) {
                return nums1[index1 + k - 1];
            }
            else if(k == 1) {
                return min(nums1[index1], nums2[index2]);
            }
            int pos1 = min(index1 + k / 2 - 1, n - 1);
            int pos2 = min(index2 + k / 2 - 1, m - 1);
            // 相等的情况并入其中一种考虑简化难度
            if(nums1[pos1] < nums2[pos2]) {
                k -= pos1 - index1 + 1;
                index1 = pos1 + 1;
            }
            else {
                k -= pos2 - index2 + 1;
                index2 = pos2 + 1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int num = nums1.size() + nums2.size();
        if(num%2 == 0) {
            return double(this->findKValue(nums1, nums2, num/2 + 1) + this->findKValue(nums1, nums2, num/2)) / 2.0;
        }
        else {
            return double(this->findKValue(nums1, nums2, num/2 + 1));
        }
    }
};
// @lc code=end

# ifdef _DEBUG
int main(int argc, char const *argv[])
{
    cout<<"start"<<endl;
    vector<int> a = {1, 2};
    vector<int> b = {3, 4};
    Solution test;
    cout<<test.findMedianSortedArrays(a, b)<<endl;
    return 0;
}

#endif

/*
 * @lc app=leetcode.cn id=798 lang=cpp
 *
 * [798] 得分最高的最小轮调
 */
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

// @lc code=start
class Solution {
public:
    /*将每个点可以得分的需要的k的区间叠加起来，找到最合适的k值
    * 区间更新+单点查询。差分数组即可
    * 对于现有的i位置，在移动k后可以得分 新下标取值 0 <= （i-k）%n <= n-1
    * 同时要保证得分，即 numes[i] <= i - k
    * 按照界限进行区间操作即可
    */
    int bestRotation(vector<int>& nums)
    {
        vector<int> diffs(nums.size() + 1, 0);
        for(size_t i = 0; i<nums.size(); i++)
        {
            if( nums[i] <= i)
            {
                // 本身可以计分，两个区间
                diffs[0]++;
                diffs[i - nums[i] + 1]--;

                diffs[i + 1]++;
                diffs[nums.size()]--;
            }
            else
            {
                diffs[i+1]++;
                diffs[i - nums[i] + nums.size() + 1]--;
            }
        }
        size_t cnt=diffs[0], k = 0;
        
        for(size_t i = 1; i< nums.size(); i++)
        {
            diffs[i] += diffs[i-1];
            if(diffs[i] > cnt){
                k = i;
                cnt = diffs[i];
            }
        }
        return k;
    }
};
// @lc code=end
# ifdef _DEBUG
int main()
{
    Solution sol;
    vector<int> nums{2,3,1,4,0};
    cout<<sol.bestRotation(nums)<<endl;
    return 0;
}
# endif

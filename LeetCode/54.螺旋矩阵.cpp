/*
 * @Author: LinXuan
 * @Date: 2022-03-16 14:43:07
 * @Description: 想不到更好、更短的解法了
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-16 14:43:18
 * @FilePath: /Algorithm/LeetCode/54.螺旋矩阵.cpp
 */
/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <bits/stdc++.h>
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define m_p make_pair
#define x first
#define y second
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using LD = long double;
using P = pair<int, int>;
const int inf = 0x3f3f3f3f;
const LL LLinf = 0x3f3f3f3f3f3f3f3f;

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int down = matrix.size(), right = matrix.begin()->size();
        int left = -1, up = -1;
        vector<int> ans;
        pair<int, int> index{0, -1};
        while (ans.size() < matrix.size() * matrix[0].size())
        {
            while (index.second + 1 < right){
                index.second++;
                ans.push_back(matrix[index.first][index.second]);
            }
            up++;

            while (index.first + 1 < down){
                index.first++;
                ans.push_back(matrix[index.first][index.second]);
            }
            right--;
            if (left < right - 1 and up < down - 1)
            {
                while (index.second - 1 > left){
                    index.second--;
                    ans.push_back(matrix[index.first][index.second]);
                }
                down--;
                 while (index.first - 1 > up){
                    index.first--;
                    ans.push_back(matrix[index.first][index.second]);
                }
                left++;
            }
        }
        return std::move(ans);
    }
    vector<int> spiralOrder_one(vector<vector<int>> &matrix)
    {
        int down = matrix.size(), right = matrix.begin()->size();
        int left = -1, up = -1;
        int k = -1;
        vector<int> ans;
        pair<int, int> index{0, -1};
        while (ans.size() < matrix.size() * matrix[0].size())
        {
            k++;
            switch (k % 4)
            {
            case 0:
                while (index.second + 1 < right)
                {
                    index.second++;
                    ans.push_back(matrix[index.first][index.second]);
                }
                up++;
                break;
            case 1:
                while (index.first + 1 < down)
                {
                    index.first++;
                    ans.push_back(matrix[index.first][index.second]);
                }
                right--;
                break;
            case 2:
                while (index.second - 1 > left)
                {
                    index.second--;
                    ans.push_back(matrix[index.first][index.second]);
                }
                down--;
                break;
            case 3:
                while (index.first - 1 > up)
                {
                    index.first--;
                    ans.push_back(matrix[index.first][index.second]);
                }
                left++;
                break;
            }
        }
        return std::move(ans);
    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Solution sol;
    for (auto i : sol.spiralOrder(matrix))
        cout << i << " ";
    return 0;
}

/*
 * @Author: LinXuan
 * @Date: 2021-08-24 11:14:39
 * @Description: 
 * @LastEditors: LinXuan
 * @LastEditTime: 2021-08-24 11:33:51
 * @FilePath: /Algorithm/LeetCode/24.两两交换链表中的节点.cpp
 */
/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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

# ifdef _DEBUG
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
# endif

class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode *pointer = new ListNode(-1, head);
        ListNode *newhead = pointer;
        while(pointer->next != nullptr and pointer->next->next !=nullptr)
        {
            ListNode *first = pointer->next;
            ListNode *second = first->next;
            pointer->next = second;
            first->next = second->next;
            second->next = first;

            pointer = first; // 移动两位
        }
        return newhead->next;
    }
};
// @lc code=end

# ifdef _DEBUG
int main(int argc, char const *argv[])
{
    cout<<"start"<<endl;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, nullptr))));
    Solution test;
    test.swapPairs(head);
    return 0;
}

# endif


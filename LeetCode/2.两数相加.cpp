/*
 * @Author: LinXuan
 * @Date: 2021-08-17 00:33:14
 * @Description: 
 * @LastEditors: LinXuan
 * @LastEditTime: 2021-08-17 01:02:15
 * @FilePath: /Algorithm/LeetCode/2.两数相加.cpp
 */
/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start

// Definition for singly-linked list.

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
// AC 有意思的题……没想到除只想指针的指针以外的解法。
// 引用不能改变指向的对象，难受
#ifdef _DEBUG
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *ans;
        ans = new ListNode();
        ListNode  **st = &ans; // 指针引用
        while(l1!=nullptr and l2!=nullptr) {
            (*st)->val = (l1->val + l2->val + carry)%10;
            carry = (l1->val + l2->val + carry)/10;
            (*st)->next = new ListNode();
            st = &((*st)->next);
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *l3 = nullptr;
        if(l1 != nullptr) l3 = l1;
        else if(l2 != nullptr) l3 = l2;
        while(l3 != nullptr) {
            (*st)->val = (carry + l3->val)%10;
            carry = (l3->val + carry)/10;
            (*st)->next = new ListNode();
            st = &((*st)->next);
            l3 = l3->next;
        }
        if(carry != 0){
            (*st)->val = carry;
        }
        else {
            delete (*st);
            (*st) = nullptr;
        }
        return ans;
    }
};
// @lc code=end
# ifdef _DEBUG
int main(int argc, char const *argv[])
{
    /* code */
    Solution test;
    ListNode *l1 = new ListNode(9, nullptr);
    ListNode *l2 = new ListNode(8, nullptr);
    auto ans = test.addTwoNumbers(l1, l2);
    cout<<"over!"<<endl;
    return 0;
}
#endif

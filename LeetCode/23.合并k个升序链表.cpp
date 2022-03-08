/*
 * @Author: linxuan
 * @Date: 2021-08-22 17:55:51
 * @Description: file conten
 * @LastEditors: linxuan
 * @LastEditTime: 2021-08-22 18:16:35
 * @FilePath: /Algorithm/LeetCode/23.合并k个升序链表.cpp
 */
/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 * 虽然可以二分分治……但是1e4个节点……直接暴力不就行了？
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


// Definition for singly-linked list.
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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        vector<int> allnode;
        for(ListNode *list : lists)
            {
                while(list != nullptr)
                {
                    allnode.push_back(list->val);
                    list = list->next;
                }
            }
        sort(allnode.begin(), allnode.end());

        ListNode *newlist, *lastpointer, *stpointer;
        newlist = new ListNode();
        lastpointer = newlist;
        for(int val : allnode)
        {
            stpointer = new ListNode(val, nullptr);
            lastpointer->next = stpointer;
            lastpointer = stpointer;
        }
        newlist = newlist->next;
        return newlist;
    }
};
// @lc code=end

#ifdef _DEBUG
    int main(int argc, char const *argv[])
    {
        ListNode *list1, *list2, *list3;
        list1 = new ListNode(1, new ListNode(4, new ListNode(5, nullptr)));
        list2 = new ListNode(1, new ListNode(3, new ListNode(4, nullptr)));
        list3 = new ListNode(2, new ListNode(6, nullptr));
        vector<ListNode*> lists = {list1, list2, list3};

        Solution test;
        test.mergeKLists(lists);
        return 0;
    }
        
#endif

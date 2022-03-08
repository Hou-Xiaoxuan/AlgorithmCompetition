/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 * 废物……一维链表翻转都忘记了
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
# ifdef _DEBUG
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
# endif
class Solution {
    ListNode* reverse(ListNode *head)
    {
        ListNode * pre = nullptr;
        ListNode *st = head->next;
        ListNode *next = st->next;
        while(st!=nullptr)
        {
            st->next = pre;
            pre = st;
            st = next;
            if(st!=nullptr)
                next = st->next;
        }
        head->next = pre;
        return head;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        
        ListNode *rt_head = new ListNode(-1, head);
        ListNode *ite_head = rt_head;
        int cnt = 0;
        ListNode *st = ite_head;
        while(st != nullptr) 
        {
            cnt++;
            st = st->next;
            if(cnt == k and st!=nullptr)
            {
                ListNode *end_next = st->next;
                st->next = nullptr;
                ListNode *head_old = ite_head->next;
                ite_head->next = reverse(ite_head)->next;
                head_old->next = end_next;
                ite_head = head_old;
                st = ite_head;
                cnt = 0;
            }

        }
        return rt_head->next;
    }

};
// @lc code=end
# ifdef _DEBUG
int main(int argc, char const *argv[])
{
    ListNode *head = 
        new ListNode(0, new ListNode(1, 
        new ListNode(2, new ListNode(3, 
        new ListNode(4, new ListNode(5, 
        new ListNode(6, new ListNode(7, nullptr))))))));
    Solution test;
    test.reverseKGroup(head, 3);
    return 0;
}

# endif

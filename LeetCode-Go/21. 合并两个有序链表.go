/*
 * @Author: LinXuan
 * @Date: 2022-03-08 15:29:14
 * @Description:
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-08 15:54:32
 * @FilePath: /Algorithm/LeetCode-Go/21. 合并两个有序链表.go
 */
package leetcodego

func mergeTwoLists(list1 *ListNode, list2 *ListNode) (rt *ListNode) {
	rt = new(ListNode)
	ans := rt
	// 指针简化代码，折磨自己
	for list1 != nil || list2 != nil {
		var tmp *(*ListNode) = nil
		if list1 == nil {
			tmp = &list2
		} else if list2 == nil {
			tmp = &list1
		} else {
			if list1.Val > list2.Val {
				tmp = &list2
			} else {
				tmp = &list1
			}
		}
		ans.Next = *tmp
		*tmp = (*tmp).Next
		ans = ans.Next
		ans.Next = nil
	}
	return rt.Next
}

func MergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	return mergeTwoLists(list1, list2)
}

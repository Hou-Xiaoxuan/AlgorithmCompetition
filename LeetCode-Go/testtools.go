/*
 * @Author: LinXuan
 * @Date: 2022-03-06 16:06:05
 * @Description: 调试工具，尽量是提交所不需要的
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-08 15:52:51
 * @FilePath: /Algorithm/LeetCode-Go/testtools.go
 */
package leetcodego

import "errors"

func slice_equal(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i, ia := range a {
		if ia != b[i] {
			return false
		}
	}
	return true
}

func max_int(a ...int) (ans int, index int, err error) {
	if len(a) == 0 {
		return -1, -1, errors.New("没有数据")
	}
	ans = a[0]
	index = 0
	for i, val := range a {
		if val > ans {
			ans = val
			index = i
		}
	}
	return
}
func min_int(a ...int) (ans int, index int, err error) {
	if len(a) == 0 {
		return -1, -1, errors.New("没有数据")
	}
	ans = a[0]
	index = 0
	for i, val := range a {
		if val < ans {
			ans = val
			index = i
		}
	}
	return
}

type ListNode struct {
	Val  int
	Next *ListNode
}

func make_list(vals ...int) *ListNode {
	ret := new(ListNode)
	tmp := ret
	for _, val := range vals {
		tmp.Next = new(ListNode)
		tmp = tmp.Next
		tmp.Val = val
	}
	return ret.Next
}

func list_equal(list1, list2 *ListNode) bool {
	// 相等判断
	if *list1 == *list2 {
		return true
	}
	for list1 != nil && list2 != nil {
		if list1.Val != list2.Val {
			return false
		}
		list1 = list1.Next
		list2 = list2.Next
	}

	return list1 == nil && list2 == nil
}

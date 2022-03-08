/*
 * @Author: LinXuan
 * @Date: 2022-03-08 15:29:14
 * @Description:
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-08 15:50:02
 * @FilePath: /Algorithm/LeetCode-Go/22. 合并两个有序链表_test.go
 */
package leetcodego

import "testing"

func TestMergeTwoLists(t *testing.T) {
	list1 := make_list(1, 3, 5, 7)
	list2 := make_list(2, 4, 6, 8)
	ans := make_list(1, 2, 3, 4, 5, 6, 7, 8)
	rt := mergeTwoLists(list1, list2)
	if list_equal(rt, ans) == false {
		t.Fatal("faild")
	}
}

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
//  8ms 4.4MB ok
package leetcodego

import "fmt"

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	ans := new(ListNode)
	ret := ans
	r := 0
	for {
		ans.Val = r
		if l1 != nil {
			ans.Val += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			ans.Val += l2.Val
			l2 = l2.Next
		}
		r = ans.Val / 10
		ans.Val -= r * 10
		if l1 != nil || l2 != nil || r > 0 {
			ans.Next = new(ListNode)
			ans = ans.Next
		} else {
			break
		}
	}
	return ret
}


func Main_2() {
	a := make_list(2, 4, 3)
	b := make_list(5, 6, 4)
	ans := addTwoNumbers(a, b)
	fmt.Print("over", ans)
}

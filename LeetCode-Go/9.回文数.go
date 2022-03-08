/*
 * @Author: LinXuan
 * @Date: 2022-03-05 17:26:46
 * @Description:
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-05 17:35:42
 * @FilePath: /LeetCode-Go/9.回文数.go
 */
package leetcodego

func isPalindrome(x int) bool {
	if x < 0 || x%10 == 0 && x != 0 {
		return false
	}
	// 2112
	var rev = 0
	for x > rev {
		rev = rev*10 + x%10
		x /= 10
	}
	return x == rev || x == rev/10
}

func Main_9() {
	_ = isPalindrome(323)
}

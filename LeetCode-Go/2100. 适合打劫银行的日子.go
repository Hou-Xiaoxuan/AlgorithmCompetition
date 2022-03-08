/*
 * @Author: LinXuan
 * @Date: 2022-03-06 15:09:52
 * @Description:
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-06 15:51:11
 * @FilePath: /Algorithm/LeetCode-Go/2100. 适合打劫银行的日子.go
 */
package leetcodego

func GoodDaysToRobBank(security []int, time int) []int {
	n := len(security)
	increase := make([]int, n)
	for i := 1; i < n; i++ {
		if security[i] <= security[i-1] {
			increase[i] = increase[i-1] + 1
		} else {
			increase[i] = 0
		}
	}
	decrease := make([]int, n)
	for i := n - 2; i >= 0; i-- {
		if security[i] <= security[i+1] {
			decrease[i] = decrease[i+1] + 1
		} else {
			decrease[i] = 0
		}
	}

	ans := make([]int, 0)

	for i := 0; i < n; i++ {
		if increase[i] >= time && decrease[i] >= time {
			ans = append(ans, i)
		}
	}
	return ans
}

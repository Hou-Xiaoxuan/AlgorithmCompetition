/*
 * @Author: LinXuan
 * @Date: 2022-03-06 16:04:42
 * @Description:
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-06 16:25:14
 * @FilePath: /Algorithm/LeetCode-Go/11.盛最多水的容器.go
 */
package leetcodego

func MaxArea(height []int) int {
	l, r := 0, len(height)-1
	// init
	ans := 0
	for l < r {
		val, index, _ := min_int(height[l], height[r])
		ans, _, _ = max_int(ans, val*(r-l))
		if index == 0 {
			l++
		} else {
			r--
		}
	}
	return ans
}

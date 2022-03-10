/*
 * @Author: LinXuan
 * @Date: 2022-03-10 10:51:11
 * @Description:
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-10 10:55:25
 * @FilePath: /Algorithm/LeetCode-Go/798. 得分最高的最小轮调.go
 */
package leetcodego

func bestRotation(nums []int) (k int) {
	n := len(nums)
	diffs := make([]int, n)
	for i := 0; i < n; i++ {
		if nums[i] <= i {
			// 本身可以计分，两个区间
			diffs[0]++
			diffs[i-nums[i]+1]--

			diffs[i+1]++
			diffs[n]--
		} else {
			diffs[i+1]++
			diffs[i-nums[i]+n+1]--
		}
	}
	cnt := diffs[0]

	for i := 1; i < n; i++ {
		diffs[i] += diffs[i-1]
		if diffs[i] > cnt {
			k = i
			cnt = diffs[i]
		}
	}
	return k
}

func BestRotation(nums []int) int {
	return bestRotation(nums)
}

/*
 * @Author: LinXuan
 * @Date: 2022-03-15 13:18:08
 * @Description: 贪心 // 想不到搞了这么久，最优解<0的多种情况没考虑到
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-15 13:39:47
 * @FilePath: /Algorithm/LeetCode-Go/53. 最大子数组和.go
 */
package leetcodego

var _ = maxSubArray

func maxSubArray(nums []int) (ans int) {
	ans = nums[0]
	tmp := -1
	// 本质上变成以val作为序列最后一个数字的一维dp了。d
	for _, val := range nums {
		// if ans < 0 {
		// 	// 保底最大的一个数字
		// 	if val > ans {
		// 		ans = val
		// 	}
		// }
		// if tmp+val > 0 {
		// 	tmp += val
		// 	if tmp > ans {
		// 		ans = tmp
		// 	}
		// } else {
		// 	tmp = 0
		// }
		if tmp < 0 {
			tmp = val
		} else {
			tmp += val
		}
		if ans < tmp {
			ans = tmp
		}
	}
	return
}

/*
 * @Author: LinXuan
 * @Date: 2022-03-08 16:00:23
 * @Description:
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-08 16:31:03
 * @FilePath: /Algorithm/LeetCode-Go/33. 搜索旋转排序数组.go
 * @Note: 找mid的逻辑错了一次。go的搜索有点不方便，但是又很灵活
 */
package leetcodego

import "sort"

/* 思路：
* 先二分找到中间点，然后根据情况选择一边进行二分。执行了两次
 */
func search(nums []int, target int) (ans int) {

	// 查找比nums[0]小的第一个数字
	n := len(nums)
	mid := sort.Search(n, func(i int) bool {
		if nums[i] >= nums[0] {
			return false
		} else {
			return true
		}
	})
	// 找不到说明为mid=0
	if mid == n {
		mid = 0
	}

	if target <= nums[n-1] {
		// [mid, n)找>=target的第一个数
		ans = sort.Search(n, func(i int) bool {
			if i < mid {
				return false
			} else {
				return nums[i] >= target
			}
		})
		if ans == n || nums[ans] != target {
			ans = -1
		}
	} else {
		// [0, mid)找
		ans = sort.Search(mid, func(i int) bool {
			return nums[i] >= target
		})
		if ans == mid || nums[ans] != target {
			ans = -1
		}
	}
	return
}

func Search(nums []int, target int) int {
	return search(nums, target)
}

/*
 * @Author: LinXuan
 * @Date: 2022-03-07 14:04:20
 * @Description:
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-07 19:07:31
 * @FilePath: /Algorithm/LeetCode-Go/16. 最接近的三数之和.go
 */
package leetcodego

import "sort"

func threeSumClosest_solve1(nums []int, target int) (ans int) {
	// 60ms
	// n^2循环 + 二分，n2log(n)
	sort.Ints(nums)
	ans = nums[0] + nums[1] + nums[2]
	dis := func(a, b int) int {
		if a > b {
			return a - b
		}
		return b - a
	}
	for i := 0; i < len(nums)-2; i++ {
		for j := i + 1; j < len(nums)-1; j++ {
			k := sort.Search(len(nums), func(index int) bool {
				// 过滤可能的元素重复，找k>j且ans>=targeth的第一个
				if index <= j {
					return false
				}
				return nums[index] >= target-nums[i]-nums[j]
			})
			// 一定要有一个和
			if k == len(nums) {
				k--
			}
			// 防止重复
			if k != j {
				if dis(ans, target) > dis(target, nums[i]+nums[j]+nums[k]) {
					ans = nums[i] + nums[j] + nums[k]
				}
			}
			// 查询ans<target的情况
			if k-1 != j {
				if dis(ans, target) > dis(target, nums[i]+nums[j]+nums[k-1]) {
					ans = nums[i] + nums[j] + nums[k-1]
				}
			}
		}
	}
	return
}

func threeSumClosest_solve2(nums []int, target int) (ans int) {
	// 4ms

	ans = nums[0] + nums[1] + nums[2]
	sort.Ints(nums)
	dis := func(a, b int) int {
		if a > b {
			return a - b
		}
		return b - a
	}
	// 用类似`2101`的双指针方法
	for i := 0; i < len(nums); i++ {
		l, r := 0, len(nums)-1
		for l < r {
			if l == i {
				l++
				continue
			} else if r == i {
				r--
				continue
			}
			tmp := nums[i] + nums[l] + nums[r]
			if dis(target, ans) > dis(target, tmp) {
				ans = tmp
			}
			if tmp < target {
				l++
			} else if tmp > target {
				r--
			} else {
				return // 最优
			}
		}
	}
	return
}

// 解决unused问题
var _, _ = threeSumClosest_solve1, threeSumClosest_solve2

func ThreeSumClosest(nums []int, target int) (ans int) {
	return threeSumClosest_solve2(nums, target)
}

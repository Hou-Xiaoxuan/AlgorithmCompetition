/*
 * @Author: LinXuan
 * @Date: 2022-03-07 14:25:36
 * @Description:
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-07 19:04:10
 * @FilePath: /Algorithm/LeetCode-Go/16. 最接近的三数之和_test.go
 */
package leetcodego

import (
	"testing"
)

func TestThreeSumClosest(t *testing.T) {
	nums := []int{0, 1, 2}
	target := 0
	ans := 3
	rt := ThreeSumClosest(nums, target)
	if rt != ans {
		t.Fatalf("return%v, but shoud be%v", rt, ans)
	}
}

func TestThreeSumClosest2(t *testing.T) {
	nums := []int{1, 2, 4, 8, 16, 32, 64, 128}
	target := 82
	ans := 82
	rt := ThreeSumClosest(nums, target)
	if rt != ans {
		t.Fatalf("return%v, but shoud be%v", rt, ans)
	}
}

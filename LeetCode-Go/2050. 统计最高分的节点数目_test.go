/*
 * @Author: LinXuan
 * @Date: 2022-03-11 20:32:49
 * @Description:
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-11 21:22:45
 * @FilePath: /Algorithm/LeetCode-Go/2050. 统计最高分的节点数目_test.go
 */
package leetcodego

import "testing"

func TestCountHighestScoreNodes(t *testing.T) {
	parents := []int{-1, 3, 4, 5, 7, 6, 0, 0}
	ans := 2
	rt := CountHighestScoreNodes(parents)
	if rt != ans {
		t.Fatalf("Expect %v, but return %v", ans, rt)
	}
}

func TestCountHighestScoreNodes2(t *testing.T) {
	parents := []int{-1, 2, 0, 2, 0}
	ans := 3
	rt := CountHighestScoreNodes(parents)
	if rt != ans {
		t.Fatalf("Expect %v, but return %v", ans, rt)
	}
}

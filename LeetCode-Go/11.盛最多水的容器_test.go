/*
 * @Author: LinXuan
 * @Date: 2022-03-06 16:16:04
 * @Description:
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-06 16:23:35
 * @FilePath: /Algorithm/LeetCode-Go/11.盛最多水的容器_test.go
 */
package leetcodego

import (
	"fmt"
	"testing"
)

func TestMaxArea(t *testing.T) {
	height := []int{1, 8, 6, 2, 5, 4, 8, 3, 7}
	ans := 49
	rt := MaxArea(height)
	if rt != ans {
		t.Fatal(fmt.Sprint("expect", ans, "but return", rt))
	}
}
func TestMaxAreaPrint(t *testing.T) {
	height := []int{2, 3, 10, 5, 7, 8, 9}
	fmt.Println("结果是: ", MaxArea(height))
}

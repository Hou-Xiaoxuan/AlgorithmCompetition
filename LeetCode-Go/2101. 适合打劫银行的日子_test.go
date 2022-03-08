/*
 * @Author: LinXuan
 * @Date: 2022-03-06 15:09:52
 * @Description:
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-06 16:06:17
 * @FilePath: /Algorithm/LeetCode-Go/2101. 适合打劫银行的日子_test.go
 */
package leetcodego

import (
	"fmt"
	"testing"
)

func TestGoodDaysToRobBank(t *testing.T) {
	security := []int{5, 3, 3, 3, 5, 6, 2}
	time := 2
	ans := []int{2, 3}
	rt := GoodDaysToRobBank(security, time)
	if slice_equal(ans, rt) == false {
		t.Fatal(fmt.Sprint("ans should be\n", ans, "\nbut is\n", rt))
	}
}

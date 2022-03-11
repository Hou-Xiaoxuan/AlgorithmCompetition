/*
 * @Author: LinXuan
 * @Date: 2022-03-11 20:32:49
 * @Description:
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-11 21:29:32
 * @FilePath: /Algorithm/LeetCode-Go/2049. 统计最高分的节点数目.go
 */
package leetcodego

/*
 * 消耗2*n的空间。
 * channel当队列，增加了一点开销
 */
func countHighestScoreNodes(parents []int) (ans int) {
	// 统计出度
	n := len(parents)
	dus := make([]int, n)
	for _, val := range parents {
		if val != -1 {
			dus[val]++
		}
	}

	// 统计每个节点之后的值
	nums := make([]int, n)
	// 节点当根时的子树大小
	cnts := make([]int, n)
	// 当队列用
	que := make(chan int, n)
	for i := 0; i < n; i++ {
		nums[i] = 1 // 默认是1
		cnts[i] = 1 // 子树本身大小
		if dus[i] == 0 {
			que <- i
		}
	}

	// 遍历
	for len(que) > 0 {
		i := <-que
		if parents[i] == -1 {
			// 已经到根了
			continue
		}
		nums[i] *= (n - cnts[i])    // 父节点的子树
		nums[parents[i]] *= cnts[i] // 向父节点累乘子树
		cnts[parents[i]] += cnts[i] // 增加父节点为根的子树大小
		dus[parents[i]]--           //清理du
		if dus[parents[i]] == 0 {
			que <- parents[i]
		}
	}

	// 统计答案
	max_value := nums[0]
	for _, val := range nums {
		if val == max_value {
			ans++
		} else if val > max_value {
			ans = 1
			max_value = val
		}
	}

	return
}

func CountHighestScoreNodes(parents []int) int {
	return countHighestScoreNodes(parents)
}

package main

import (
	"fmt"
	"sort"
)

func search(nums []int, target int) bool {
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})

	//fmt.Printf("nums:")
	//for i := range len(nums) {
	//	fmt.Printf("%d ", nums[i])
	//}

	lft := 0
	rht := len(nums) - 1

	for lft <= rht {
		//fmt.Printf("%d - %d\n", lft, rht)
		mid := lft + (rht-lft)/2
		curr := nums[mid]
		if curr == target {
			return true
		} else if target > curr {
			lft = mid + 1
		} else if target < curr {
			rht = mid - 1
		}
	}
	return false
}

func main() {
	//nums := []int{2, 5, 6, 0, 0, 1, 2}
	//fmt.Println(search(nums, 0))
	//fmt.Println()
	// 0 0 1 2 2 5 6
	nums1 := []int{1}
	fmt.Println(search(nums1, 1))
}

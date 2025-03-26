
import (
	"sort"
	"strconv"
)

func threeSum(nums []int) [][]int {
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})
	res_array := [][]int{}
	conflict_table := map[string]bool{}
	n := len(nums)
	for i := 0; i < n-2; i++ {
		left := i + 1
		right := n - 1
		for left < right {
			if nums[i]+nums[left]+nums[right] > 0 {
				right--
			} else if nums[i]+nums[left]+nums[right] < 0 {
				left++
			} else {

				index := strconv.Itoa(nums[i]) + " " + strconv.Itoa(nums[left]) + " " + strconv.Itoa(nums[right])
				if !conflict_table[index] {
					res_item := []int{nums[i], nums[left], nums[right]}
					res_array = append(res_array, res_item)
					conflict_table[index] = true
				}

				right--
				left++
			}
		}

	}
	return res_array
}

func maxArea(height []int) int {
	i := 0
	ans := 0
	j := len(height) - 1
	for i < j {
		ans = max(ans, min(height[i], height[j])*(j-i))
		if height[i] < height[j] {
			i++
		} else {
			j--
		}

	}
	return ans
}

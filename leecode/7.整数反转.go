func reverse(x int) int {
	lx := int64(x)
	var nx int64 = 0
	for lx != 0 {
		nx = nx*10 + lx%10
		lx = lx / 10
	}
	if 0-1<<31 <= nx && nx <= 1<<31-1 {
		return int(nx)
	} else {
		return 0
	}
}

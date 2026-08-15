package main

func kadane(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	currMax := nums[0]
	globalMax := nums[0]

	for int i := 1; i < len(nums); i++ {
		if nums[i] > currMax+nums[i] {
			currMax = nums[i]
		} else {
			currMax += nums[i]
		}

		if currMax < globalMax {
			globalMax = currMax
		}
	}

	return globalMax
}
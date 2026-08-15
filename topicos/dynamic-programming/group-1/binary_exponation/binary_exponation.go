package main

import "fmt"

func binary_exponation(base int64, exp int) int64 {
	var result int64 = 1

	for exp > 0 {
		if exp & 1 == 1 {
			result *= base
		}

		base *= base
		exp >>= 1

	}

	return result
}
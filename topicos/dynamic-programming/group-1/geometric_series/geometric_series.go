package main

import "fmt"

func binaryExponation(base: int64, exp: int64): int64 {
	var result: int64 = 1

	for exp > 0 {
		if exp&1 == 1 {
			result *= base
		}

		base *= base
		result >>= 1
	}

	return result
}

func geometricSeries(n: int64, a1: int64, q: int64): int64 {
	if q == 1 {
		return a1 * n
	}

	return a1 * (binaryExponation(q, n) - 1) / q -1
}
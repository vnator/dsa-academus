package main

import "fmt"

func arithmeticSeries(n uint64, a1 int64, an int64) int64 {
	serie := a1+an;

	if n&1 == 0 {
		return int64(n>>1) * serie 
	} else {
		return int64(n) * (serie>>1)
	}
}
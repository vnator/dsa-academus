package main

import "fmt"

func main() {
	var inputA int
	var inputB int

	fmt.Printf("Entre com o primeiro valor numerico maior que zero: ")
	fmt.Scan(&inputA)

	fmt.Printf("Entre com o segundo valor numerico maior que zero: ")
	fmt.Scan(&inputB)

	if inputA == 0 || inputB == 0 {
		fmt.Printf("Tu digitastes zero, paiassu")
		return
	}

	primeNumberList := []int{2}

	min := 1
	max := findMaxCommonDivisor(inputA, inputB)

	if max == 1 {
		fmt.Print("Min = Max = 1")
		return
	}

	for {
		lastPrime := primeNumberList[len(primeNumberList)-1]

		if max%inputA == 0 {
			min = lastPrime
			break
		}

		nextPrimeNumber := findNextPrimeNumber(primeNumberList)

		primeNumberList = append(primeNumberList, nextPrimeNumber)

		if lastPrime > max {
			break
		}
	}

	fmt.Printf("Min divisor comum %d, Max divisor comum %d", min, max)
}

func findNextPrimeNumber(list []int) int {
	var size = len(list)
	var candidate = list[size-1]

	for {
		var isPrime = true

		if candidate == 2 {
			candidate = 3
		} else {
			candidate += 2
		}

		for _, p := range list {
			if (candidate % p) == 0 {
				isPrime = false
				break
			}
		}

		if isPrime {
			return candidate
		}
	}
}

func findMaxCommonDivisor(a int, b int) int {
	if b == 0 {
		return a
	}

	c := a % b

	return findMaxCommonDivisor(b, c)
}

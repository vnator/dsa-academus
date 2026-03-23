package main

import "fmt"

func main() {
	var size int

	fmt.Printf("Digite o tamanho da lista: ")
	fmt.Scan(&size)

	list := make([]int, size)

	fmt.Printf("Entre com uma lista de numeros naturais positivos separados por espaco e digite ENTER: ")

	for i := 0; i < size; i++ {
		fmt.Scan(&list[i])
	}

	for _, item := range list {
		isPrime := isPrimeNumber(item)

		if isPrime {
			fmt.Printf("O numero %d eh primo \n", item)
		} else {
			fmt.Printf("O numero %d nao eh primo \n", item)
		}
	}

}

func exponentialMod(base int, potency int, divisor int) int {
	result := uint64(1)
	b := uint64(base % divisor)
	d := uint64(divisor)

	for potency > 0 {
		if potency%2 == 1 {
			result = (result * b) % d
		}

		potency = potency / 2
		b = (b * b) % d
	}

	return int(result)
}

func isPrimeNumber(n int) bool {
	list := [...]int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}

	if n < 2 {
		return false
	}

	for _, item := range list {
		if n == item {
			return true
		}
		if n%item == 0 {
			return false
		}
	}

	d := n - 1
	s := 0

	for d%2 == 0 {
		d = d / 2
		s++
	}

	for _, a := range list {

		if a <= n {
			break
		}

		x := exponentialMod(a, d, n)

		if x == 1 || x == n-1 {
			continue
		}

		finishLoop := false

		for i := 1; i < s; i++ {
			x = (x * x) % n

			if x == n-1 {
				finishLoop = true
				break
			}
		}

		if !finishLoop {
			return false
		}
	}

	return true
}

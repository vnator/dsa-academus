package main

import "fmt"

func main() {
	var input int
	var counter int

	fmt.Printf("Digite o tamanho da lista: ")
	fmt.Scan(&input)

	list := make([]int, input)

	fmt.Printf("Entre com uma lista de numeros separadas por espaco e digite ENTER quando terminar:")

	for i := 0; i < input; i++ {
		fmt.Scan(&list[i])
	}

	for _, item := range list {
		if item%2 == 0 {
			counter++
		}
	}

	fmt.Printf("vc digitou %d numeros pares", counter)
}

package main

import "fmt"

func main() {
	var size int

	fmt.Printf("Digite o tamanho da lista: ")
	fmt.Scan(&size)

	list := make([]int, size)

	fmt.Printf("Entre com os elementos da lista separados por espaco e pressione Enter quando terminar: ")
	for i := 0; i < size; i++ {
		fmt.Scan(&list[i])
	}

	for size > 0 {
		fmt.Printf("%d ", list[size-1])
		size--
	}
}

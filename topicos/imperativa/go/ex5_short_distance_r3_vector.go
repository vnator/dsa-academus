package main

import (
	"fmt"
	"math"
)

type R3Vector struct {
	x float64
	y float64
	z float64
}

func main() {
	var n int

	fmt.Printf("Quantos vetores vc ira digitar? ")
	fmt.Scan(&n)

	if n < 2 {
		fmt.Println("Erro: Preciso de pelo menos 2 pontos.")
		return
	}

	list := make([]R3Vector, n)

	fmt.Println("\nDigite os vetores (ex: 12 23 33.5):")

	for i := 0; i < n; i++ {
		fmt.Printf("Vetor %d: ", i+1)
		fmt.Scan(&list[i].x, &list[i].y, &list[i].z)
	}

	var shortDistance float64
	electedVectors := make([]R3Vector, 2)

	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			distance := r3Distance(list[i], list[j])

			if (i == 0 && j == 1) || distance < shortDistance {
				shortDistance = distance
				electedVectors[0] = list[i]
				electedVectors[1] = list[j]
			}
		}
	}

	fmt.Printf("\nMenor distancia encontrada: %.4f\n", shortDistance)
	fmt.Printf("Entre Ponto A: %+v e Ponto B: %+v\n",
		electedVectors[0], electedVectors[1])
}

func r3Distance(a, b R3Vector) float64 {
	dx := b.x - a.x
	dy := b.y - a.y
	dz := b.z - a.z
	return math.Sqrt(dx*dx + dy*dy + dz*dz)
}

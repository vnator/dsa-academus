package biblioteca

import "fmt"

type Livro struct {
	isbn     string
	Titulo   string
	Autor    string
	Leitores []Leitor
}

func NewLivro(isbn, titulo, autor string) *Livro {
	return &Livro{
		Titulo:   titulo,
		Autor:    autor,
		isbn:     isbn,
		Leitores: make([]Leitor, 0),
	}
}

func (l Livro) incluirLeitor(leitor Leitor) {
	l.Leitores = append(l.Leitores, leitor)
}

func (l Livro) imprimirLeitores() {
	for i := 0; i < len(l.Leitores); i++ {
		fmt.Printf("\n%s leu %d", l.Leitores[i].Nome, l.Titulo)
	}
}

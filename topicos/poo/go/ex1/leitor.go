package biblioteca

import "fmt"

type Leitor struct {
	Idade      int
	Nome       string
	LivroAtual Livro
}

func NewLeitor(idade int, nome string, livro Livro) *Leitor {
	return &Leitor{
		Idade:      idade,
		Nome:       nome,
		LivroAtual: livro,
	}
}

func (l Leitor) novoLivro(livro Livro) {
	l.LivroAtual = livro
}

func (l Leitor) OqueEstaLendo() {
	fmt.Printf("%s esta lendo: %s, do autor %s", l.Nome, l.LivroAtual.Titulo, l.LivroAtual.Autor)
}

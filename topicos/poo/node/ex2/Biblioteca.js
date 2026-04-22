export class Biblioteca {
  #colecao;
  #emprestimos;

  constructor(livros = []) {
    this.#colecao = [...livros];
    this.#emprestimos = [];
  }


  addLivroColecao(livro) {
    this.#colecao.push(livro);
  }

  registraEmprestimo(livro, leitor) {
    const emprestimo = {
      livro,
      leitor,
      momento: new Date()
    };

    this.#emprestimos.push(emprestimo);
    leitor.setLivro(livro);

    return emprestimo;
  }

  buscarLivro(autor) {
    return this.#colecao.find(item => item.autor === autor);
  }
}

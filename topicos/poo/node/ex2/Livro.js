export default class Livro {
  #ISBN;
  titulo;
  autor;
  leitores;

  constructor(ISBN, titulo, autor) {
    this.#ISBN = ISBN;
    this.titulo = titulo;
    this.autor = autor;
    this.leitores = [];
  }

  incluirLeitor(leitor) {
    if (!this.leitores.includes(leitor)) {
      this.leitores.push(leitor);
    }
  }

  imprimirLeitores() {
    for (let leitor of this.leitores) {
      console.log(`\n${leitor.nome} leu ${this.titulo}.`);
    }
  }
}

export default class Leitor {
  idade;
  nome;
  livro;


  constructor(idade, nome, livro) {
    this.idade = idade;
    this.nome = nome;
    this.setLivro(livro);
  }


  oqueEstaLendo() {
    console.log(`${this.nome} esta lendo ${this.livro.titulo} escrito por ${this.livro.autor}`);
  }

  setLivro(livro) {
    this.livro = livro;
    this.livro.incluirLeitor(this);
  }
}

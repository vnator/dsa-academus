import { Biblioteca } from './Biblioteca.js';
import Leitor from './Leitor.js';
import Livro from './Livro.js';


function main() {
  const biblioteca = new Biblioteca();

  // livros 
  const livro_1 = new Livro("1234", "O senhor dos Aneis", "JRR Tolkien");
  const livro_2 = new Livro("2342d", "A arte de ler e meditar", "Hugo de Sao Vitor");

  biblioteca.addLivroColecao(livro_1);
  biblioteca.addLivroColecao(livro_2);

  // leitores
  const leitor_1 = new Leitor(29, "Nereu de Oliveira", livro_1);
  const leitor_2 = new Leitor(36, "Joao Henrique Serodio", livro_2);

  biblioteca.registraEmprestimo(livro_1, leitor_1);
  biblioteca.registraEmprestimo(livro_2, leitor_2);

  // livro 2 tambem foi lido por leitor_1
  biblioteca.registraEmprestimo(livro_2, leitor_1);

  const livroBuscado = biblioteca.buscarLivro("Hugo de Sao Vitor");

  if (livroBuscado) {
    console.log(`Livro encontrado: ${livroBuscado.titulo}.`);
  }

  leitor_1.oqueEstaLendo();
  leitor_2.oqueEstaLendo();

  // lista de livros
  livro_1.imprimirLeitores();
  livro_2.imprimirLeitores();
}

main();

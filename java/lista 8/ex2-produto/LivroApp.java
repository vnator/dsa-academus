public class LivroApp {
  public static void main(String[] args) {
    Produto produto1 = new Produto("Xbox Series x", 700.00);
    Produto produto2 = new Produto("Controle Xbox", 80.00);

    Livro livroA = new Livro("Algoritmos e estruturas de dados descomplicada em C", 78.00, "Andre Backer", 400);
    Livro livroB = new Livro("Como meditar e aprender", 20.00, "Hugo de São Vitor", 30);

    System.out.println("Produto 1");

    System.out.println("nome: " + produto1.nome);
    System.out.println("preco: " + produto1.preco);
    System.out.println("é caro: " + (produto1.ehCaro() ? "sim" : "nao"));
    System.out.println("é Caro para um console de media 1000 reais no preco? " + (produto1.ehCaro(1000) ? "sim" : "nao"));

    System.out.println("-----------------------\n\n");
  
    System.out.println("Produto 2");
    System.out.println("nome: " + produto2.nome);
    System.out.println("preco: " + produto2.preco);
    System.out.println("é caro: " + (produto2.ehCaro() ? "sim" : "nao"));
    System.out.println("é Caro para um controle de media 50 reais no preco? " + (produto2.ehCaro(50) ? "sim" : "nao"));

    System.out.println("-----------------------\n\n");
  
    System.out.println("Livro A");
    System.out.println("nome: " + livroA.nome);
    System.out.println("preco: " + livroA.preco);
    System.out.println("autor: " + livroA.getAutor());
    System.out.println("paginas: " + livroA.getPaginas());
    System.out.println("é caro: " + (livroA.ehCaro() ? "sim" : "nao"));
    System.out.println("é Caro para um livro de media 150 reais no preco? " + (livroA.ehCaro(150) ? "sim" : "nao"));
    System.out.println("é extenso: " + (livroA.ehExtenso() ? "sim" : "nao"));

    System.out.println("-----------------------\n\n");
  
    System.out.println("Livro B");
    System.out.println("nome: " + livroB.nome);
    System.out.println("preco: " + livroB.preco);
    System.out.println("autor: " + livroB.getAutor());
    System.out.println("paginas: " + livroB.getPaginas());
    System.out.println("é caro: " + (livroB.ehCaro() ? "sim" : "nao"));
    System.out.println("é Caro para um livro de media 150 reais no preco? " + (livroB.ehCaro(150) ? "sim" : "nao"));

    System.out.println("-----------------------\n\n");}
}

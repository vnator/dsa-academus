public class TesteLivro {

    public static void main(String[] args) {
        Livro meuLivro = new Livro("Lord of the Rings", "JRR Tolkien");

        System.out.println("teste get titulo: " + meuLivro.getTitulo());
        System.out.println("teste get autor: " + meuLivro.getAutor());
        
        System.out.println("atualizando informação e rodando exibeDados ");

        meuLivro.setTitulo("O nome do vento");
        meuLivro.setAutor("Patrick Rothfuss");

        meuLivro.exibeDados();
    }
}

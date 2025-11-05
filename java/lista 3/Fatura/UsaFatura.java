public class UsaFatura {
    public static void main(String[] args) {
        Fatura minhaFatura = new Fatura("12345", "Teclado Mecânico", 2, 150.0);

        System.out.println("Valores iniciais:");
        System.out.println("Número: " + minhaFatura.getNumero());
        System.out.println("Descrição: " + minhaFatura.getDescricao());
        System.out.println("Quantidade: " + minhaFatura.getQtdItem());
        System.out.println("Preço: " + minhaFatura.getPreco());
        System.out.println("Valor da fatura: " + minhaFatura.getQtdeFatura());

        minhaFatura.setNumero("67890");
        minhaFatura.setDescricao("Mouse Gamer");
        minhaFatura.setQtdItem(3);
        minhaFatura.setPreco(200.0);

        System.out.println("\nValores após alteração:");
        System.out.println("Número: " + minhaFatura.getNumero());
        System.out.println("Descrição: " + minhaFatura.getDescricao());
        System.out.println("Quantidade: " + minhaFatura.getQtdItem());
        System.out.println("Preço: " + minhaFatura.getPreco());
        System.out.println("Novo valor da fatura: " + minhaFatura.getQtdeFatura());
    }
}

public class App {
    public static void main(String[] args) {
        Funcionario f = new Funcionario("João", 30, "Analista");
        Gerente g = new Gerente("Maria", 40, "TI");

        System.out.println(f);
        System.out.println(g);
    }
}
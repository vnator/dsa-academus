public class ExercicioQuatro {
    public static void main(String[] args) {
        int soma = 0;

        for (int i = 1; i <= 10; i++) {
            System.out.println(i);
            soma += i;
        }

        System.out.println("A soma dos números de 1 a 10 é: " + soma);
    }
}
public class ExercicioDois {
    public static void main(String[] args) {
        int numero1 = 10;
        int numero2 = 5;
        int soma = numero1 + numero2;
        int subtracao = numero1 - numero2;
        int multiplicacao = numero1 * numero2;
        double divisao = (double) numero1 / numero2;
        System.out.println(
            "Números: " + numero1 + " e " + numero2 + 
            "\n Soma: " + soma + 
            "\n Subtração: " + subtracao + 
            "\n Multiplicação: " + multiplicacao + 
            "\n Divisão: " + divisao
        );
    }
}
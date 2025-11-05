public class ExercicioCinco {
    public static void main(String[] args) {
        int numero = 5;
        long fatorial = calcularFatorial(numero);
        
        System.out.println("O fatorial de " + numero + " é: " + fatorial);
    }

   public static long calcularFatorial(int n) {
        long resultado = 1;
        int contador = 1;


        while (contador <= n) {
            resultado *= contador;
            contador++;
        }

        return resultado;
    }
}E
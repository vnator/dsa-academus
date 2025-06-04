public class Soma {
    public static void soma(int[] numeros) {

        int resultado = 0;
        for (int numero : numeros) {
            resultado += numero;
        }
        
        System.out.println(resultado);
    }
}

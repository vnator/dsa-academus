public class Exercicio8 {
    public static void main(String[] args) {
        int[] vetor = new int[] { 2, 4, 6, 8, 10, 12 };
        
        try {
            for (int i = 0; i < 12; i++) {
                System.out.println(vetor[i]);
            }
        } catch (ArrayIndexOutOfBoundsException exc) {
            System.out.println("Fim do vetor!");
        }
    }
}
public class Exercicio7 {
    public static void main(String[] args) {
        int[] vetor = new int[] { 2, 4, 6, 8, 10 };
        
        try {
            for (int i = 0; i < 6; i++) {
                System.out.println(vetor[i]);
            }
        } catch (ArrayIndexOutOfBoundsException exc) {
            System.out.println("Final do vetor!");
        }
    }
}
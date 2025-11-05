public class Exercicio8Demonstracao {
    
    public static void exemploSemTratamento() {
        System.out.println("=== EXEMPLO SEM TRATAMENTO DE EXCEÇÃO ===");
        int[] vetor = new int[] { 2, 4, 6, 8, 10, 12 };
        
        try {
            for (int i = 0; i < 12; i++) {
                System.out.println("Posição " + i + ": " + vetor[i]);
            }
        } catch (Exception e) {
            System.out.println("Exceção capturada: " + e.getClass().getSimpleName());
            System.out.println("Mensagem: " + e.getMessage());
            System.out.println("Fim do vetor!");
        }
    }
    
    public static void exemploComTratamento() {
        System.out.println("\n=== EXEMPLO COM TRATAMENTO ESPECÍFICO ===");
        int[] vetor = new int[] { 2, 4, 6, 8, 10, 12 };
        
        try {
            for (int i = 0; i < 12; i++) {
                System.out.println("Posição " + i + ": " + vetor[i]);
            }
        } catch (ArrayIndexOutOfBoundsException exc) {
            System.out.println("Fim do vetor!");
        }
    }
    
    public static void main(String[] args) {
        exemploSemTratamento();
        exemploComTratamento();
        
        System.out.println("\n=== INFORMAÇÕES SOBRE O VETOR ===");
        int[] vetor = new int[] { 2, 4, 6, 8, 10, 12 };
        System.out.println("Tamanho do vetor: " + vetor.length);
        System.out.println("Tentativa de acessar 12 posições (0 a 11)");
        System.out.println("Posições válidas: 0 a " + (vetor.length - 1));
    }
}

public class ExemplosExcecoes {
    

    public static void exemploMultiplosCatches() {
        System.out.println("=== EXEMPLO: MÚLTIPLOS CATCHES ===");
        
        try {
            String str = null;
            int[] array = {1, 2, 3};
            
            System.out.println(str.length());
            
            System.out.println(array[5]);
            
        } catch (NullPointerException e) {
            System.out.println("Erro: Tentativa de usar objeto nulo");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Erro: Índice fora dos limites do array");
        } catch (Exception e) {
            System.out.println("Erro genérico: " + e.getMessage());
        }
    }
    
    public static void exemploTryCatchFinally() {
        System.out.println("\n=== EXEMPLO: TRY-CATCH-FINALLY ===");
        
        try {
            int resultado = 10 / 0;
            System.out.println("Resultado: " + resultado);
        } catch (ArithmeticException e) {
            System.out.println("Erro: Divisão por zero não é permitida");
        } finally {
            System.out.println("Bloco finally sempre executa");
        }
    }
    
    public static void exemploTryWithResources() {
        System.out.println("\n=== EXEMPLO: SIMULAÇÃO TRY-WITH-RESOURCES ===");
        
        try {
            System.out.println("Abrindo recurso...");
            
            int[] array = {1, 2, 3};
            System.out.println(array[10]);
            
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Erro capturado: " + e.getMessage());
        } finally {
            System.out.println("Fechando recurso...");
        }
    }
    
    public static void metodoQuePodeGerarExcecao() throws ArrayIndexOutOfBoundsException {
        int[] array = {1, 2, 3};
        System.out.println(array[5]);
    }
    
    public static void exemploProgagacao() {
        System.out.println("\n=== EXEMPLO: PROPAGAÇÃO DE EXCEÇÃO ===");
        
        try {
            metodoQuePodeGerarExcecao();
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Exceção capturada no método chamador");
        }
    }
    
    public static void main(String[] args) {
        exemploMultiplosCatches();
        exemploTryCatchFinally();
        exemploTryWithResources();
        exemploProgagacao();
        
        System.out.println("\n=== RESUMO DAS BOAS PRÁTICAS ===");
        System.out.println("1. Sempre trate exceções específicas antes das genéricas");
        System.out.println("2. Use finally para código de limpeza");
        System.out.println("3. Não capture exceções que você não pode tratar");
        System.out.println("4. Forneça mensagens de erro claras para o usuário");
        System.out.println("5. Use try-with-resources para gerenciar recursos automaticamente");
    }
}
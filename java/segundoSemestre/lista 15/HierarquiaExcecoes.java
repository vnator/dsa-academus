public class HierarquiaExcecoes {
    
    public static void demonstrarException() {
        System.out.println("=== DEMONSTRAÇÃO: EXCEPTION ===");
        
        try {
            throw new NullPointerException("Simulando NullPointerException");
        } catch (RuntimeException e) {
            System.out.println("Capturou RuntimeException: " + e.getClass().getSimpleName());
        }
        
        try {
            throw new ArrayIndexOutOfBoundsException("Simulando ArrayIndexOutOfBoundsException");
        } catch (RuntimeException e) {
            System.out.println("Capturou RuntimeException: " + e.getClass().getSimpleName());
        }
        
        try {
            throw new Exception("Simulando Exception genérica");
        } catch (Exception e) {
            System.out.println("Capturou Exception: " + e.getClass().getSimpleName());
        }
    }
    
    public static void demonstrarError() {
        System.out.println("\n=== DEMONSTRAÇÃO: ERROR (apenas para fins didáticos) ===");
        System.out.println("ATENÇÃO: Na prática, NÃO devemos lançar Error manualmente!");
        
        try {
            throw new Error("Simulando Error (APENAS PARA DEMONSTRAÇÃO)");
        } catch (Error e) {
            System.out.println("Capturou Error: " + e.getClass().getSimpleName());
            System.out.println("Mensagem: " + e.getMessage());
        }
    }
    
    public static void mostrarHierarquia() {
        System.out.println("\n=== HIERARQUIA DE THROWABLE ===");
        System.out.println("1. Throwable");
        System.out.println("1.1 Exception");
        System.out.println("1.1.1 RuntimeException (unchecked)");
        System.out.println("1.1.1.1 NullPointerException");
        System.out.println("1.1.1.2 ArrayIndexOutOfBoundsException");
        System.out.println("1.1.1.3 IllegalArgumentException");
        System.out.println("1.1.1.4 NumberFormatException");
        System.out.println("1.1.1.5 ...");
        System.out.println("1.1.2 IOException (checked)");
        System.out.println("1.1.3 SQLException (checked)");
        System.out.println("1.1.4 ClassNotFoundException (checked)");
        System.out.println("1.1.5 ...");
        System.out.println("1.2 Error (unchecked)");
        System.out.println("1.2.1 OutOfMemoryError");
        System.out.println("1.2.2 StackOverflowError");
        System.out.println("1.2.3 VirtualMachineError");
        System.out.println("1.2.4 ...");
    }
    
    public static void demonstrarPorqueNaoError() {
        System.out.println("\n=== POR QUE NÃO LANÇAR ERROR? ===");
        System.out.println("1. Error indica problemas GRAVES do sistema/JVM");
        System.out.println("2. Aplicações geralmente NÃO conseguem se recuperar de Errors");
        System.out.println("3. Quebra convenções e expectativas dos desenvolvedores");
        System.out.println("4. Exception é para problemas da aplicação");
        System.out.println("5. Error é para problemas da infraestrutura/JVM");
        
        System.out.println("\n CORRETO - Use Exception:");
        System.out.println("   throw new IllegalArgumentException(\"Argumento inválido\");");
        System.out.println("   throw new RuntimeException(\"Erro de processamento\");");
        System.out.println("   throw new CustomException(\"Erro de negócio\");");
        
        System.out.println("\n INCORRETO - Não use Error:");
        System.out.println("   throw new Error(\"Validação falhou\");");
        System.out.println("   throw new OutOfMemoryError(\"Sem memória\");");
    }
    
    public static void demonstrarCapturaHierarquia() {
        System.out.println("\n=== CAPTURA POR HIERARQUIA ===");
        
        try {
            throw new NumberFormatException("Erro de formato");
        } catch (Exception e) {
            System.out.println("Exception capturou: " + e.getClass().getSimpleName());
        }
        
        try {
            throw new IllegalArgumentException("Argumento inválido");
        } catch (RuntimeException e) {
            System.out.println("RuntimeException capturou: " + e.getClass().getSimpleName());
        }
        
        try {
            throw new RuntimeException("Qualquer exceção");
        } catch (Throwable t) {
            System.out.println("Throwable capturou: " + t.getClass().getSimpleName());
        }
    }
    
    public static void main(String[] args) {
        demonstrarException();
        demonstrarError();
        mostrarHierarquia();
        demonstrarPorqueNaoError();
        demonstrarCapturaHierarquia();
        
        System.out.println("\n=== RESUMO ===");
        System.out.println(" Throwable tem duas subclasses diretas: Exception e Error");
        System.out.println(" Exception: para problemas que aplicações podem tratar");
        System.out.println(" Error: para problemas graves do sistema/JVM");
        System.out.println(" Use Exception (não Error) em seu código");
        System.out.println(" Capture específico antes de genérico na hierarquia");
    }
}
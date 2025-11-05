public class ExemplosLista15 {
    
    public static void exemploMultiplasExcecoes() {
        System.out.println("=== EXEMPLO 1: MÚLTIPLAS EXCEÇÕES ===");
        
        try {
            String[] args = {"abc", "123"};
            int index = 5;
            String valor = args[index];
            int numero = Integer.parseInt(valor);
            
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Catch específico: Índice fora dos limites");
        } catch (NumberFormatException e) {
            System.out.println("Catch específico: Formato de número inválido");
        } catch (Exception e) {
            System.out.println("Catch genérico: " + e.getClass().getSimpleName());
        }
        
        try {
            String[] args = {"abc"};
            int numero = Integer.parseInt(args[10]);
            
        } catch (ArrayIndexOutOfBoundsException | NumberFormatException e) {
            System.out.println("Multi-catch: " + e.getClass().getSimpleName());
        }
    }
    
    public static void exemploSuperclasseCaptura() {
        System.out.println("\n=== EXEMPLO 2: SUPERCLASSE CAPTURA SUBCLASSES ===");
        
        try {
            throw new ArrayIndexOutOfBoundsException("Erro de índice");
            
        } catch (RuntimeException e) {
            System.out.println("Capturado por RuntimeException: " + e.getClass().getSimpleName());
        }
        
        try {
            throw new NumberFormatException("Erro de formato");
            
        } catch (Exception e) {
            System.out.println("Capturado por Exception: " + e.getClass().getSimpleName());
        }
    }
    
    public static void exemploTryAninhados() {
        System.out.println("\n=== EXEMPLO 3: TRY ANINHADOS E PROPAGAÇÃO ===");
        
        try {
            System.out.println("Try externo iniciado");
            
            try {
                System.out.println("Try interno iniciado");
                int[] arr = {1, 2, 3};
                System.out.println(arr[10]);
                
            } catch (NumberFormatException e) {
                System.out.println("Catch interno: NumberFormatException");
            }
            System.out.println("Esta linha não será executada");
            
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Catch externo: Exceção propagada do try interno");
        }
    }
    
    public static void exemploRelancamento() {
        System.out.println("\n=== EXEMPLO 4: RELANÇAMENTO DE EXCEÇÕES ===");
        
        try {
            try {
                throw new RuntimeException("Exceção original");
                
            } catch (RuntimeException e) {
                System.out.println("Catch interno: " + e.getMessage());
                System.out.println("Fazendo log e relançando...");
                throw e;
            }
            
        } catch (RuntimeException e) {
            System.out.println("Catch externo: " + e.getMessage());
        }
    }
    
    public static void exemploThrow() {
        System.out.println("\n=== EXEMPLO 5: USO DO THROW ===");
        
        try {
            validarIdade(-5);
        } catch (IllegalArgumentException e) {
            System.out.println("Exceção capturada: " + e.getMessage());
        }
        
        try {
            validarEmail("email_invalido");
        } catch (IllegalArgumentException e) {
            System.out.println("Exceção capturada: " + e.getMessage());
        }
    }
    
    private static void validarIdade(int idade) {
        if (idade < 0) {
            throw new IllegalArgumentException("Idade não pode ser negativa: " + idade);
        }
        if (idade > 150) {
            throw new IllegalArgumentException("Idade muito alta: " + idade);
        }
    }
    
    private static void validarEmail(String email) {
        if (email == null || !email.contains("@")) {
            throw new IllegalArgumentException("Email inválido: " + email);
        }
    }
    
    public static void exemploExcecaoAposCaptura() {
        System.out.println("\n=== EXEMPLO 6: EXCEÇÃO APÓS CAPTURA ===");
        
        try {
            try {
                int resultado = 10 / 0;
            } catch (ArithmeticException e) {
                System.out.println("Capturei ArithmeticException: " + e.getMessage());
                throw new RuntimeException("Erro processando divisão", e);
            }
        } catch (RuntimeException e) {
            System.out.println("Nova exceção capturada: " + e.getMessage());
            System.out.println("Causa original: " + e.getCause().getClass().getSimpleName());
        }
    }
    
    public static void exemploAnaliseFluxo() {
        System.out.println("\n=== EXEMPLO 7: ANÁLISE DE FLUXO ===");
        
        System.out.println("Blocos try-catch independentes:");
        try {
            metodoA();
        } catch (Exception e) {
            System.out.println("Tratando erro do método A");
        }
        
        try {
            metodoB();
        } catch (Exception e) {
            System.out.println("Tratando erro do método B");
        }
        
        System.out.println("Programa continua após ambos os blocos");
        
        System.out.println("\nBloco try-catch único:");
        try {
            metodoA();
            metodoB();
        } catch (Exception e) {
            System.out.println("Tratando erro - metodoB() não foi executado");
        }
    }
    
    private static void metodoA() {
        System.out.println("Executando método A");
        throw new RuntimeException("Erro no método A");
    }
    
    private static void metodoB() {
        System.out.println("Executando método B");
    }
    
    public static void exemploFinally() {
        System.out.println("\n=== EXEMPLO 8: BLOCO FINALLY ===");
        
        try {
            System.out.println("Executando try");
            throw new RuntimeException("Erro no try");
        } catch (RuntimeException e) {
            System.out.println("Executando catch");
        } finally {
            System.out.println("Executando finally");
        }
        
        System.out.println("Código APÓS o bloco try-catch-finally");
        System.out.println("Finally NÃO é a última coisa executada!");
    }
    
    public static void main(String[] args) {
        exemploMultiplasExcecoes();
        exemploSuperclasseCaptura();
        exemploTryAninhados();
        exemploRelancamento();
        exemploThrow();
        exemploExcecaoAposCaptura();
        exemploAnaliseFluxo();
        exemploFinally();
    }
}
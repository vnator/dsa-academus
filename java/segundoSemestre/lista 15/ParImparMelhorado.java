public class ParImparMelhorado {
    public static void main(String args[]) {
        try {
            validarArgumentos(args);
            
            int num = Integer.parseInt(args[0]);
            
            String resultado = verificarParImpar(num);
            System.out.println(resultado);
            
        } catch (NumberFormatException e) {
            System.err.println("Erro: '" + args[0] + "' não é um número válido.");
            mostrarInstrucoes();
        } catch (IllegalArgumentException e) {
            System.err.println("Erro: " + e.getMessage());
            mostrarInstrucoes();
        } catch (Exception e) {
            System.err.println("Erro inesperado: " + e.getMessage());
        }
    }
    
    private static void validarArgumentos(String[] args) {
        if (args.length == 0) {
            throw new IllegalArgumentException("Nenhum argumento fornecido");
        }
        if (args.length > 1) {
            throw new IllegalArgumentException("Muitos argumentos fornecidos. Use apenas um número.");
        }
    }
    
    private static String verificarParImpar(int numero) {
        if (numero % 2 == 0) {
            return numero + " é um número par";
        } else {
            return numero + " é um número ímpar";
        }
    }
    
    private static void mostrarInstrucoes() {
        System.out.println("\nUso correto:");
        System.out.println("  java ParImparMelhorado <número>");
        System.out.println("\nExemplos:");
        System.out.println("  java ParImparMelhorado 42");
        System.out.println("  java ParImparMelhorado -17");
        System.out.println("  java ParImparMelhorado 0");
    }
}
public class ParImpar {
    public static void main(String args[]) {
        int num;
        try {
            if (args.length == 0) {
                throw new ArrayIndexOutOfBoundsException("Nenhum argumento fornecido");
            }
            
            num = Integer.parseInt(args[0]);
            
            if ((num % 2) == 0) {
                System.out.println("Número par");
            } else {
                System.out.println("Número impar");
            }
        } catch (NumberFormatException e) {
            System.out.println("Erro: O argumento fornecido não é um número válido.");
            System.out.println("Use: java ParImpar <número>");
            System.out.println("Exemplo: java ParImpar 42");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Erro: Nenhum argumento foi fornecido.");
            System.out.println("Use: java ParImpar <número>");
            System.out.println("Exemplo: java ParImpar 42");
        }
    }
}
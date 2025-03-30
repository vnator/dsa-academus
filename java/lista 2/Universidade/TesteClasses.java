public class TesteClasses {
    public static void main(String[] args) {
        Aluno joao = new Aluno("João Henrique Serodio", "Matematica Aplicada Computacional");
        Universidade unicentro = new Universidade();

        unicentro.setNome("Unicentro");
        unicentro.setCidade("Guarapuava");
        unicentro.setEstado("Paraná");

        unicentro.exibeDados();
        joao.exibeDados();
    }
}
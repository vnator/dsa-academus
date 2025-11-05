public class Aluno {
    private String nome;
    private String curso;


    // Deixei um com atribuiçao na inicializaçaso por metodo construtor
    public Aluno(String nome, String curso) {
        this.nome = nome;
        this.curso = curso;
    }

    public void exibeDados() {
        System.out.println("Aluno: " + nome + ", Curso: "+ curso);
    }
}
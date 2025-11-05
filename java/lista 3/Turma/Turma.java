public class Turma {
    private String curso, disciplina;

    public String getCurso() {
        return this.curso;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }

    public String getDisciplina() {
        return this.disciplina;
    }

    public void setDisciplina(String disciplina) {
        this.disciplina = disciplina;
    }

    public void exibeDados() {
        System.out.println("Curso: " + curso);
        System.out.println("Disciplina: " + disciplina);
    }
}
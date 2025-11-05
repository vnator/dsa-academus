public class TesteTurma {

    public static void main(String[] args) {
        Turma minhaTurma = new Turma();

        minhaTurma.setCurso("Matemática Computacional");
        minhaTurma.setDisciplina("Álgebra Linear");

        System.out.println("Teste get curso: " + minhaTurma.getCurso());
        System.out.println("Teste get disciplina: " + minhaTurma.getDisciplina());

        System.out.println("Atualizando informações e rodando exibeDados");

        minhaTurma.setCurso("Física");
        minhaTurma.setDisciplina("Física Experimental 2");

        minhaTurma.exibeDados();
    }
}

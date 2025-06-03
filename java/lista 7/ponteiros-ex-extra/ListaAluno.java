public class ListaAluno {
  public static void main(String[] args) {
    Aluno[] alunos = new Aluno[10];
    alunos[0] = new Aluno("João", 1);
    alunos[1] = new Aluno("Maria", 2);
    alunos[2] = new Aluno("Pedro", 3);
    alunos[3] = new Aluno("Ana", 4);
    alunos[4] = new Aluno("Lucas", 5);
    alunos[5] = new Aluno("Fernanda", 6);
    alunos[6] = new Aluno("Carlos", 7);
    alunos[7] = new Aluno("Juliana", 8);
    alunos[8] = new Aluno("Roberto", 9);
    alunos[9] = new Aluno("Patrícia", 10);

    for (int i = 0; i < alunos.length; i++) {
      alunos[i].print();
    }
  }
}

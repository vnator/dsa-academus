
/*
 * Definiçao de classe: A classe é um projeto que define o modelo de um objeto que pode ser manipulado.
 */
public class ClasseConceito {

    // Definiçao de atributo: os atributos são as caracteristicas que o objeto terá, sao informaçoes com tipos pre definidos. 
    private String conceitoAtributo;

    public String getConceitoAtributo() {
        return this.conceitoAtributo;
    }

    public void setConceitoAtributo(String conceitoAtributo) {
        this.conceitoAtributo = conceitoAtributo;
    }

    // o metodo sao os eventos que definem o comportamento da classe ou objeto, se estático se refere especificamente a classe.
    public void conceitoMetodo() {
        System.out.println("O metodo está sendo executado e mostrando o atributo: "+conceitoAtributo);
    }

}


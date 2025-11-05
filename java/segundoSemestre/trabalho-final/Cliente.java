import java.util.ArrayList;
import java.util.List;

class Cliente extends Pessoa {
    String endereco;
    String telefone;
    List<Veiculo> veiculos;

    Cliente(String nome, int idade, String cpf, String endereco, String telefone) {
        super(nome, idade, cpf);
        this.endereco = endereco;
        this.telefone = telefone;
        veiculos = new ArrayList<>();
    }

    void putVeiculo(Veiculo veiculo) {
        veiculos.add(veiculo);
    }

    Veiculo getVeiculo(String placa) {
        for (Veiculo veiculo : veiculos) {
            if (veiculo.getPlaca().equals(placa)) {
                return veiculo;
            }
        }
        return null;
    }

    List<Veiculo> getVeiculos() {
        return veiculos;
    }
}
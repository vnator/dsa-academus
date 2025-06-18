import java.util.List;
import java.util.Iterator;

public class Oficina {
  List<Veiculo> veiculos;

  public Oficina(List<Veiculo> veiculos) {
    this.veiculos = veiculos;
  }

  public void setVeiculos(Veiculo v) {
    this.veiculos.add(v);
  }

  public void removeVeiculo(Veiculo v) {
    this.veiculos.remove(v);
  }

  public void concertar(Veiculo v) {
    v.verificar();
    v.ajustar();
    v.limpar();

    removeVeiculo(v);
  }

  public void concertarTodos() {
    Iterator<Veiculo> it = veiculos.iterator();
    while (it.hasNext()) {
      Veiculo v = it.next();
      v.verificar();
      v.ajustar();
      v.limpar();
      it.remove();
    }
  }
}
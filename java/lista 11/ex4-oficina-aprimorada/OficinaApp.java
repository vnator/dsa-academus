public class OficinaApp {
  public static void main(String[] args) {
    Veiculo automovel = new Automovel();
    Veiculo bicicleta = new Bicicleta();
    Caminhao caminhao = new Caminhao();

    Oficina oficina = new Oficina();

    oficina.concertar(automovel);
    oficina.concertar(bicicleta);
    oficina.concertar(caminhao);
  }
}

/**
 * IMPACTO
 * baixo, apenas instanciei mais um objeto (Caminhao), e executei o concertar, se tivesse deixado uma lsita de automoveis,
 */

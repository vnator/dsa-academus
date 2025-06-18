class AnimalApp {
    public static void main(String[] args) {
      Animal lista[] = {
      new Gato(),
      new Cachorro(),
      new Preguica()
    };

    for (Animal animal : lista) {
      animal.emitirSom();
    }
  }
}

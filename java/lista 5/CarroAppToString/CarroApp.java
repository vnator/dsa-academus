class CarroApp {

  public static void main(String[] args) {
    Motor motor1 = new Motor("V8");
    Banco banco1 = new Banco("Recaro");
    Carro carro1 = new Carro("Ford", "Mustang", "Ford Motor Company", motor1, banco1);


    Motor motor2 = new Motor("V6");
    Banco banco2 = new Banco("Sparco");
    Carro carro2 = new Carro("Chevrolet", "Camaro", "General Motors", motor2, banco2);

    Motor motor3 = new Motor("I4");
    Banco banco3 = new Banco("Corbeau");
    Carro carro3 = new Carro("Honda", "Civic", "Honda Motor Co.", motor3, banco3);

    System.out.println(carro1);
    System.out.println(carro2);
    System.out.println(carro3);

  }
}

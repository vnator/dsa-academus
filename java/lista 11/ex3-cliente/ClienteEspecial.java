public class ClienteEspecial extends Cliente {
    @Override
    public double calcularDesconto(double valor) {
        return valor * 0.2;
    }
}

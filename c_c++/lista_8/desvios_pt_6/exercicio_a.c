// Fazer uma solução que permita ao usuário entrar com um número. Em seguida,
// o usuário poderá escolher uma das operações: fazer o dobro, o triplo, o
// quádruplo, ou o quíntuplo desse número. Depois deverá mostrar o número
// informado pelo usuário, a operação realizada e o resultado da operação


int main () {
    int a, b;

    printf("Entre com um valor: ");
    scanf("%d", &a);

    printf("\nVoce quer o? 2: O Dobro, 3: O Triplo, 4: O Quadruplo ou 5: O Quintoplo?");
    scanf("%d", &b);

    prinf("\nValor digitado: %d \nOperação: ", a);

    switch (b) {
        case 2:
            prinf("dobro -> %d", a*b);
            break;
        case 3:
            prinf("triplo -> %d", a*b);
            break;
        case 4:
            prinf("quadruplo -> %d", a*b);
            break;
        case 5:
            prinf("quintuplo -> %d", a*b);
            break;
        default:
            prinf("Invalida")
            break;
    }
}
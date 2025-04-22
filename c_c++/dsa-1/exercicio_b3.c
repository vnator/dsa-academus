#include <stdio.h>

int main() {
    int gosta_matematica;
    char* teorema_arquimedes = "O volume de uma esfera é (4/3) * pi * r^3.";
    char* fato_arquimedes = "Arquimedes criou o conceito de pi e desenvolveu técnicas fundamentais para cálculos de áreas e volumes.";

    printf("Você gosta de matemática? 1 = sim, 0 = não: ");
    scanf("%d", &gosta_matematica);

    printf("%s\n", gosta_matematica ? teorema_arquimedes : fato_arquimedes);

    return 0;
}
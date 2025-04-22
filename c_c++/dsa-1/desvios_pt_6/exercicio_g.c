#include <stdio.h>
#include <math.h>

int main() {
    int escolha;
    double raio, lado, base, altura, area;

    printf("Escolha uma figura geometrica:\n");
    printf("0 - Circulo\n");
    printf("1 - Quadrado\n");
    printf("2 - Retangulo\n");
    printf("3 - Triangulo\n");
    scanf("%d", &escolha);

    switch(escolha) {
        case 0:
            printf("Entre com o raio do circulo: ");
            scanf("%lf", &raio);
            area = M_PI * raio * raio;
            printf("Figura: Circulo\n");
            printf("Area: %.2lf\n", area);
            break;
        case 1:
            printf("Entre com o lado do quadrado: ");
            scanf("%lf", &lado);
            area = lado * lado;
            printf("Figura: Quadrado\n");
            printf("Area: %.2lf\n", area);
            break;
        case 2:
            printf("Entre com a base do retangulo: ");
            scanf("%lf", &base);
            printf("Entre com a altura do retangulo: ");
            scanf("%lf", &altura);
            area = base * altura;
            printf("Figura: Retangulo\n");
            printf("Area: %.2lf\n", area);
            break;
        case 3:
            printf("Entre com a base do triangulo: ");
            scanf("%lf", &base);
            printf("Entre com a altura do triangulo: ");
            scanf("%lf", &altura);
            area = (base * altura) / 2;
            printf("Figura: Triangulo\n");
            printf("Area: %.2lf\n", area);
            break;
        default:
            printf("Opcao invalida\n");
            break;
    }

    return 0;
}

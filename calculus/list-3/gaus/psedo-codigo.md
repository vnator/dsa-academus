## Pseudo Código
Algoritmo com pseudo código para eliminação de Gaus.

```
Algoritmo EliminacaoGauss
Inicio
    Definir N como 5
    Definir Matriz A[N][N]
    Definir Vetor b[N]
    Definir Vetor x[N]
    Definir variaveis mult, soma

    Para k de 1 ate N-1 faca
        Se A[k][k] == 0 entao
            Escrever "Erro: Pivô nulo. O sistema não pode ser resolvido sem pivoteamento."
            Retornar
        FimSe

        Para i de k+1 ate N faca
            mult = A[i][k] / A[k][k]
            Para j de k+1 ate N faca
                A[i][j] = A[i][j] - (mult * A[k][j])
            FimPara
            b[i] = b[i] - (mult * b[k])
        FimPara
    FimPara

    Se A[N][N] == 0 entao
        Escrever "Erro: Sistema singular detectado na última etapa."
        Retornar
    FimSe

    x[N] = b[N] / A[N][N]

    Para i de N-1 ate 1 passo -1 faca
        soma = b[i]
        Para j de i+1 ate N faca
            soma = soma - (A[i][j] * x[j])
        FimPara
        x[i] = soma / A[i][i]
    FimPara
Fim
```
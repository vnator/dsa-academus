1) Desenvolva um validador de cartão conforme o algoritmo:

-   Extrair digitos de um Integer;
-   Dobrar cada segundo valor a partir da direita;
-   Somar os dígitos de cada valor;
-   Soma mod 10 == 0, então cartão é válido

2) Escreva uma função skips que a partir de uma lista retorna cada i-ésimo elemento, ou seja, o primeiro valor é a entrada, o segundo é cada outro elemento (segundo, quarto, sexto, ...) e assim por diante:

skips :: [a] -> [[a]]\
skips "ABCD" == ["ABCD", "BD", "C", "D"]\
skips "hello!" == ["hello!", "el!", "l!", "l", "o", "!"]\
skips [] == []

3) Escreva uma função localMaxima que encontra os elementos que não possuem vizinhos (antecessor e sucessor) maiores que ele. Observe que o primeiro e o último elementos não podem ser máximos:

localMaxima :: [a] -> [a]\
localMaxima [2, 9, 5, 6, 1] == [9, 6]\
localMaxima [2, 3, 4, 1, 5] == [4]\
localMaxima [1, 2, 3, 4, 5] == []

4) Implemente uma função xor, que aplica o operador lógico xor em uma lista de Bool.

5) Implemente uma função para calcular o i-ésimo número de Fibonacci.

6) Implemente uma função para criar uma lista com a sequência de Fibonacci. Note que [0..] cria uma lista com os números naturais.

7) Implemente uma versão mais rápida, utilizando programação dinâmica, para gerar a sequência de Fibonacci.

8) Implemente uma versão ainda mais rápida para gerar a sequência. Verifique o site <https://www.nayuki.io/page/fast-fibonacci-algorithms> para encontrar algoritmos mais rápidos.
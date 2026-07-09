% --- Casos Base (Números) ---
avaliar(X, X) :- 
    number(X).

% --- Operações Matemáticas ---
avaliar(A + B, Resultado) :-
    avaliar(A, ResA),
    avaliar(B, ResB),
    Resultado is ResA + ResB.

avaliar(A - B, Resultado) :-
    avaliar(A, ResA),
    avaliar(B, ResB),
    Resultado is ResA - ResB.

avaliar(A * B, Resultado) :-
    avaliar(A, ResA),
    avaliar(B, ResB),
    Resultado is ResA * ResB.

avaliar(A / B, Resultado) :-
    avaliar(A, ResA),
    avaliar(B, ResB),
    ResB \= 0,
    Resultado is ResA / ResB.

% --- Ponto de Entrada (Execução Automática) ---
main :-
    % Define a expressão a ser avaliada
    Expressao = ((2 + 3) * (7 - 4)),
    
    % Executa o interpretador
    avaliar(Expressao, Resultado),
    
    % Imprime o resultado formatado na tela
    format('Resultado de ~w = ~w~n', [Expressao, Resultado]),
    
    % Finaliza a execução do Prolog de forma limpa
    halt.

% Esta diretiva diz ao Prolog para rodar o 'main' assim que o arquivo carregar
:- initialization(main).
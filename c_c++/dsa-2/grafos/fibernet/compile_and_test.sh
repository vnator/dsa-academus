#!/bin/bash

# Script de compilação e teste para FiberNet

echo "=== Compilando FiberNet ==="
g++ -std=c++17 -O2 -Wall -Wextra -o fibernet fibernet.cpp

if [ $? -eq 0 ]; then
    echo "✅ Compilação bem-sucedida!"
    echo
    
    echo "=== Executando testes ==="
    ./fibernet < input.txt > output.txt
    
    echo "--- Saída obtida ---"
    cat output.txt
    echo
    
    echo "--- Saída esperada ---"
    cat output_esperado.txt
    echo
    
    echo "=== Comparando resultados ==="
    if diff -q output.txt output_esperado.txt > /dev/null; then
        echo "✅ TESTE PASSOU! Saída correta."
    else
        echo "❌ TESTE FALHOU! Diferenças encontradas:"
        diff output.txt output_esperado.txt
    fi
else
    echo "❌ Erro na compilação!"
    exit 1
fi
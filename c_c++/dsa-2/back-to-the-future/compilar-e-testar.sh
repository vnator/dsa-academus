#!/bin/bash

echo "==================================="
echo "  Back to the Future - Compilação WSL"
echo "==================================="
echo ""

# Verificar se está no WSL
if [[ -n "$WSL_DISTRO_NAME" ]]; then
    echo "✓ Executando no WSL: $WSL_DISTRO_NAME"
else
    echo "⚠ Não detectado WSL - mas continuando..."
fi
echo ""

# Verificar se GCC está instalado
if ! command -v g++ &> /dev/null; then
    echo "✗ GCC/G++ não encontrado!"
    echo "Execute: sudo apt update && sudo apt install -y gcc g++ build-essential"
    exit 1
fi

echo "✓ GCC versão: $(g++ --version | head -1)"
echo ""

# Compilar
echo "Compilando back-to-the-future.cpp..."
g++ -o back-to-the-future back-to-the-future.cpp -std=c++17 -Wall -O2

if [ $? -eq 0 ]; then
    echo "✓ Compilação bem-sucedida!"
    echo ""
    
    echo "==================================="
    echo "  Executando com casos de teste"
    echo "==================================="
    echo ""
    
    # Executar com timeout para evitar loops infinitos
    timeout 10s ./back-to-the-future < entrada.txt > saida-obtida.txt
    
    if [ $? -eq 124 ]; then
        echo "✗ Programa excedeu tempo limite (10s)"
        exit 1
    fi
    
    echo "--- Saída obtida ---"
    cat saida-obtida.txt
    
    echo ""
    echo "--- Saída esperada ---"
    cat saida-esperada.txt
    
    echo ""
    echo "==================================="
    echo "  Verificando resultados"
    echo "==================================="
    
    # Normalizar quebras de linha e comparar
    tr -d '\r' < saida-obtida.txt > temp-obtida.txt
    tr -d '\r' < saida-esperada.txt > temp-esperada.txt
    
    if diff -w temp-obtida.txt temp-esperada.txt > /dev/null; then
        echo "✓ TODOS OS TESTES PASSARAM!"
        echo ""
        echo "🎉 Algoritmo Min-Cost Max-Flow funcionando corretamente!"
        echo "📊 Instância 1: 80 (10×1 + 10×7)"
        echo "📊 Instância 2: 140 (20×7)" 
        echo "📊 Instância 3: impossível (capacidade insuficiente)"
    else
        echo "✗ Diferenças encontradas:"
        diff temp-obtida.txt temp-esperada.txt
        echo ""
        echo "💡 Debug: Verifique a implementação do SPFA ou fluxo residual"
    fi
    
    # Limpar arquivos temporários
    rm -f temp-obtida.txt temp-esperada.txt
    
else
    echo "✗ Erro na compilação"
    echo "Verifique se o arquivo back-to-the-future.cpp existe"
fi

echo ""
echo "==================================="
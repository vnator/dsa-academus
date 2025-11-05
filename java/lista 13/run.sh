#!/bin/bash

echo "==================================="
echo "  Compilando Simulação de Baralho"
echo "==================================="
echo ""

# Criar diretório build
mkdir -p build

# Compilar
echo "Compilando..."
javac -d build Naipe.java Valor.java Carta.java Baralho.java Main.java

if [ $? -eq 0 ]; then
    echo "✓ Compilação concluída!"
    echo ""
    echo "==================================="
    echo "  Executando Simulação"
    echo "==================================="
    echo ""
    java -cp build Main
    echo ""
    echo "==================================="
else
    echo "✗ Erro na compilação"
fi

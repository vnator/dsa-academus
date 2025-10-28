#!/bin/bash

# Script para compilar e executar o sistema de Oficina

echo "==================================="
echo "  Sistema de Gerenciamento de Oficina"
echo "==================================="
echo ""

# Criar diretório build se não existir
echo "1. Criando diretório de build..."
mkdir -p build
echo "   ✓ Diretório build criado/verificado"
echo ""

# Compilar todas as classes
echo "2. Compilando classes..."

# Compilar exceções primeiro
echo "   - Compilando exceções..."
javac -d build ServicoIndisponivelException.java VeiculoNaoEncontradoException.java MecanicoNaoEspecializadoException.java
if [ $? -ne 0 ]; then
    echo "   ✗ Erro ao compilar exceções"
    exit 1
fi

# Compilar enums e interfaces
echo "   - Compilando enums e interfaces..."
javac -d build TipoVeiculo.java Reparavel.java
if [ $? -ne 0 ]; then
    echo "   ✗ Erro ao compilar enums/interfaces"
    exit 1
fi

# Compilar classes base
echo "   - Compilando classes base..."
javac -d build -cp build Pessoa.java
if [ $? -ne 0 ]; then
    echo "   ✗ Erro ao compilar Pessoa"
    exit 1
fi

# Compilar classes derivadas e outras
echo "   - Compilando classes principais..."
javac -d build -cp build Cliente.java Mecanico.java Veiculo.java Servico.java OrdemServico.java Oficina.java
if [ $? -ne 0 ]; then
    echo "   ✗ Erro ao compilar classes principais"
    exit 1
fi

# Compilar classe de teste
echo "   - Compilando TesteOficina..."
javac -d build -cp build TesteOficina.java
if [ $? -ne 0 ]; then
    echo "   ✗ Erro ao compilar TesteOficina"
    exit 1
fi

echo "   ✓ Todas as classes compiladas com sucesso!"
echo ""

# Executar teste
echo "3. Executando TesteOficina..."
echo "==================================="
echo ""
java -cp build TesteOficina
echo ""
echo "==================================="
echo "✓ Execução concluída!"

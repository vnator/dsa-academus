# Makefile para Problema das Acácias

# Variáveis
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = acacias
SOURCE = acacias.cpp
INPUT = entrada.txt

# Regra principal
all: $(TARGET)

# Compilação
$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)

# Executar com arquivo de entrada
run: $(TARGET)
	./$(TARGET) < $(INPUT)

# Executar com entrada manual
test: $(TARGET)
	./$(TARGET)

# Teste com comparação
check: $(TARGET)
	./$(TARGET) < $(INPUT) > saida-obtida.txt
	@if diff -q saida-obtida.txt saida-esperada.txt >/dev/null 2>&1; then \
		echo "✓ Teste passou! Saída correta."; \
	else \
		echo "✗ Teste falhou! Diferenças encontradas:"; \
		diff saida-obtida.txt saida-esperada.txt; \
	fi

# Limpeza
clean:
	rm -f $(TARGET) $(TARGET).exe saida-obtida.txt

# Para Windows
windows: $(SOURCE)
	g++ -o $(TARGET).exe $(SOURCE)

# Executar no Windows
run-windows: $(TARGET).exe
	$(TARGET).exe < $(INPUT)

# Debug
debug: $(SOURCE)
	$(CXX) $(CXXFLAGS) -g -DDEBUG -o $(TARGET)-debug $(SOURCE)

.PHONY: all run test check clean windows run-windows debug
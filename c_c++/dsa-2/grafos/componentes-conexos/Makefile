# Makefile para Componentes Conexos

# Variáveis
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = componentes-conexos
SOURCE = componentes-conexos.cpp
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

# Limpeza
clean:
	rm -f $(TARGET) $(TARGET).exe

# Para Windows
windows: $(SOURCE)
	g++ -o $(TARGET).exe $(SOURCE)

# Executar no Windows
run-windows: $(TARGET).exe
	$(TARGET).exe < $(INPUT)

.PHONY: all run test clean windows run-windows
# Especifica o compilador
CXX = g++

# Opções de compilação
CXXFLAGS = -fsanitize=address -std=c++11 -Wall -O0 -g -W -ansi -pedantic

# Nome do arquivo de saída
TARGET = kanban

# Diretório para os arquivos objeto
BUILD_DIR = build

# Diretório para o arquivo executável
BIN_DIR = bin

# Arquivos de origem
SOURCES = src/main.cpp src/functions.cpp src/classes.cpp

# Gera os nomes dos arquivos objeto com base nos arquivos de origem
OBJECTS = $(patsubst src/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Caminho para o arquivo executável
EXECUTABLE = $(BIN_DIR)/$(TARGET)

# Regra principal para a compilação
all: $(EXECUTABLE)

# Regra para gerar o arquivo executável
$(EXECUTABLE): $(OBJECTS)
	@echo "Compilando o programa..."
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)
	@echo "Executável criado no diretório 'bin'"

# Regra para compilar os arquivos objeto
$(BUILD_DIR)/%.o: src/%.cpp
	@echo "Compilando o arquivo objeto $@..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cria a pasta build, se não existir
$(shell mkdir -p $(BUILD_DIR))

# Cria a pasta bin, se não existir
$(shell mkdir -p $(BIN_DIR))

# Regra para executar o programa
run:
	@echo "Executando o programa..."
	./$(EXECUTABLE)

# Limpa os arquivos objeto e o executável
clean:
	@echo "Removendo arquivos.."
	rm -f $(OBJECTS) $(EXECUTABLE)

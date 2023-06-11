# Especifica o compilador
CXX = g++

# Opções de compilação
CXXFLAGS = -fsanitize=address -std=c++11 -Wall -O0 -g -W -ansi -pedantic

# Nome do arquivo de saída
TARGET = kanban

# Diretório para o código fonte
SRC_DIR = src

# Diretório para os arquivos objeto
BUILD_DIR = build

# Diretório para o arquivo executável
BIN_DIR = bin

# Arquivos de origem
SOURCES =  $(wildcard $(SRC_DIR)/*$(SRC_EXT))

# Gera os nomes dos arquivos objeto com base nos arquivos de origem
OBJECTS = $(patsubst src/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

create_directories:
	mkdir -p $(BUILD_DIR) $(BIN_DIR)


# Caminho para o arquivo executável
EXECUTABLE = $(BIN_DIR)/$(TARGET)

# Regra principal para a compilação
all: create_directories $(EXECUTABLE)

# Regra para compilar os objetos
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | create_directories
	@echo "Compilando o arquivo objeto $@..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

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

# Limpa os arquivos objeto, o executável e os diretórios
clean:
	@echo "Removendo arquivos e diretórios.."
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Limpa somente os arquivos
clean_files:
	@echo "Removendo arquivos..."
	rm -f $(OBJECTS) $(EXECUTABLE)

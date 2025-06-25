# Nome do executável
TARGET = slem

# Diretórios
SRC_DIR = src
INCLUDE_DIR = include

# Arquivos fonte
SRCS = main.cpp $(SRC_DIR)/locais.cpp

# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -I$(INCLUDE_DIR)

# Compilar e gerar o executável
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Limpa o executável (compatível com Git Bash e Unix)
clean:
	rm -f $(TARGET).exe $(TARGET)

# Roda o programa (compila e executa)
run: all
	./$(TARGET).exe

# Recompila tudo do zero
rebuild: clean all

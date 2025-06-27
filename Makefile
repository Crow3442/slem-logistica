# Nome do executável
TARGET = slem

# Diretórios
SRC_DIR = src
INCLUDE_DIR = include

# Arquivos fonte
SRCS = main.cpp \
       $(SRC_DIR)/locais.cpp \
       $(SRC_DIR)/veiculos.cpp \
       $(SRC_DIR)/pedidos.cpp

# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -I$(INCLUDE_DIR)

# Regra principal
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Executar o programa
run: all
	./$(TARGET).exe

# Limpar o executável
clean:
	rm -f $(TARGET).exe $(TARGET)

# Limpar e recompilar
rebuild: clean all
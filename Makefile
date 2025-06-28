# Compilador
CC = g++
CFLAGS = -Wall -Iinclude

SRC = main.cpp src/locais.cpp src/veiculos.cpp src/pedidos.cpp src/sistema.cpp
BIN = slem

# ======================== Sistema Principal ========================
all: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) -o $(BIN) $(SRC)

run: $(BIN)
	./$(BIN)

# ======================== Scripts de Dados ========================
dados: locais veiculos pedidos

locais: tools/criar_dados_locais.cpp
	$(CC) $(CFLAGS) -o tools/locais tools/criar_dados_locais.cpp
	tools/locais

veiculos: tools/criar_dados_veiculos.cpp
	$(CC) $(CFLAGS) -o tools/veiculos tools/criar_dados_veiculos.cpp
	tools/veiculos

pedidos: tools/criar_dados_pedidos.cpp
	$(CC) $(CFLAGS) -o tools/pedidos tools/criar_dados_pedidos.cpp
	tools/pedidos

# ======================== Limpeza ========================

# Remove apenas o executável principal
clean:
	-@rm -f $(BIN).exe 2>/dev/null || del /Q $(BIN).exe

# Remove apenas os executáveis dos scripts de dados
clean-tools:
	-@rm -f tools/locais.exe tools/veiculos.exe tools/pedidos.exe 2>/dev/null || \
	del /Q tools\locais.exe tools\veiculos.exe tools\pedidos.exe

# Remove tudo
clean-all: clean clean-tools
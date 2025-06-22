# Nome do executável
TARGET = slem

# Compilador
CC = gcc

# Diretórios
SRC_DIR = src
INC_DIR = includes

# Arquivos fonte
SRCS = $(SRC_DIR)/locais.c \
       $(SRC_DIR)/veiculos.c \
       $(SRC_DIR)/pedidos.c \
       $(SRC_DIR)/util.c \
       main.c

# Arquivos objeto
OBJS = $(SRCS:.c=.o)

# Flags de compilação
CFLAGS = -Wall -I$(INC_DIR)

# Regra principal
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Regra para gerar .o de cada .c
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Limpa arquivos compilados
clean:
	rm -f $(SRC_DIR)/*.o *.o $(TARGET)

# Limpa tudo (binários e backups)
clean-all: clean
	rm -f data/*.bin

.PHONY: all clean clean-all
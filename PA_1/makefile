# Diretórios
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Arquivos
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
EXEC = $(BIN_DIR)/pa1.out

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=gnu11 -I$(INCLUDE_DIR)

# Regra padrão (gera o binário)
all: $(EXEC)

# Compilar e linkar
$(EXEC): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Compilar os arquivos .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Criar diretórios se não existirem
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Limpar arquivos compilados
clean:
	rm -rf $(OBJ_DIR)/*.o $(EXEC)

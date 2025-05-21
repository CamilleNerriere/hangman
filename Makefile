# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude

# Dossiers
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

# Fichiers source
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Fichiers objets correspondants
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Nom de l'exécutable
TARGET = hangman

# Règle par défaut
all: $(TARGET)

# Lier les objets pour créer l'exécutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilation des .c en .o dans obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Crée le dossier obj/ s'il n'existe pas
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Nettoyage
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
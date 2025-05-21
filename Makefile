CC = gcc
CFLAGS = -Wall -Wextra -g
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Fichiers source et objets
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

# Nom de l'exécutable
TARGET = hangman

# Règle par défaut
all: $(BUILD_DIR) $(TARGET)

# Création du répertoire build si nécessaire
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compilation de l'exécutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilation des fichiers objets
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Nettoyage
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Règle pour exécuter le programme
run: all
	./$(TARGET)

.PHONY: all clean run
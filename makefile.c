# Variabili
CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =
SRCDIR = src
BINDIR = bin
INCDIR = include
LIBDIR = lib

# File sorgente
SRC_MAIN = $(SRCDIR)/main.c
SRC_TEST = $(SRCDIR)/test.c
SRC_COMMON = $(SRCDIR)/common.c

# File oggetto
OBJ_MAIN = $(SRC_MAIN:.c=.o) $(SRC_COMMON:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o) $(SRC_COMMON:.c=.o)

# Eseguibili
EXEC_MAIN = $(BINDIR)/main_ex1
EXEC_TEST = $(BINDIR)/test_ex1

# Target di default
all: $(EXEC_MAIN) $(EXEC_TEST)

# Compilazione di main_ex1
$(EXEC_MAIN): $(OBJ_MAIN)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(OBJ_MAIN) -o $(EXEC_MAIN) $(LDFLAGS)

# Compilazione di test_ex1
$(EXEC_TEST): $(OBJ_TEST)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(OBJ_TEST) -o $(EXEC_TEST) $(LDFLAGS) -lunity

# Regola generica per compilare i file .c
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Pulizia
clean:
	rm -rf $(SRCDIR)/*.o $(BINDIR)

# Esegui i test
run_tests: $(EXEC_TEST)
	$(EXEC_TEST)

# Esempio di utilizzo
default:
	@echo "Usa 'make all' per compilare o 'make run_tests' per eseguire i test."

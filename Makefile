# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 20:10:19 by nerfy             #+#    #+#              #
#    Updated: 2024/07/07 03:45:54 by nerfy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and compilation options
# Compilateur et options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

# Source directories
# Répertoires sources
SRCDIR = utils
PARSINGDIR = $(SRCDIR)/parsings
HELPERSDIR = $(SRCDIR)/main_helpers
DICTIONARYDIR = $(SRCDIR)/dictionary

# Include directories
# Répertoires d'inclusion
INCDIR = $(SRCDIR) $(PARSINGDIR) $(HELPERSDIR) $(DICTIONARYDIR)

# Source files
# Fichiers sources
SRC = main.c \
      $(DICTIONARYDIR)/dictionary.c \
      $(DICTIONARYDIR)/dictionary_helpers.c \
      $(DICTIONARYDIR)/buffer_processing1.c \
      $(DICTIONARYDIR)/buffer_processing2.c \
      $(HELPERSDIR)/main_helpers1.c \
      $(HELPERSDIR)/main_helpers2.c \
      $(HELPERSDIR)/main_helpers3.c \
      $(SRCDIR)/string_utils.c \
      $(SRCDIR)/memory_utils.c \
      $(PARSINGDIR)/parsing.c \
      $(SRCDIR)/functions.c \
      $(PARSINGDIR)/scale_words.c \
      $(PARSINGDIR)/handling.c \
      $(PARSINGDIR)/utility.c 

# Object files
# Fichiers objets
OBJ = $(SRC:.c=.o)

# Executable name
# Nom de l'exécutable
NAME = rush-02

# Default rule
# Règle par défaut
all: $(NAME)

# Linking the executable
# Lien de l'exécutable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(foreach DIR,$(INCDIR),-I$(DIR))

# Compilation rules for .c to .o in SRCDIR
# Compilation des fichiers .c en fichiers .o pour le répertoire SRCDIR
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< $(foreach DIR,$(INCDIR),-I$(DIR))

# Compilation rules for .c to .o in PARSINGDIR
# Compilation des fichiers .c en fichiers .o pour le répertoire PARSINGDIR
$(PARSINGDIR)/%.o: $(PARSINGDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< $(foreach DIR,$(INCDIR),-I$(DIR))

# Compilation rules for .c to .o in HELPERSDIR
# Compilation des fichiers .c en fichiers .o pour le répertoire HELPERSDIR
$(HELPERSDIR)/%.o: $(HELPERSDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< $(foreach DIR,$(INCDIR),-I$(DIR))

# Compilation rules for .c to .o in DICTIONARYDIR
# Compilation des fichiers .c en fichiers .o pour le répertoire DICTIONARYDIR
$(DICTIONARYDIR)/%.o: $(DICTIONARYDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< $(foreach DIR,$(INCDIR),-I$(DIR))

# Cleaning object files
# Nettoyage des fichiers objets
clean:
	rm -f $(OBJ)

# Full clean
# Nettoyage complet
fclean: clean
	rm -f $(NAME)

# Rebuild everything
# Recompilation complète
re: fclean all

.PHONY: all clean fclean re
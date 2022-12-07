NAME = minishell

SRC_PATH 	= src/
SRC_OBJ		= objs/
SRC_HEADER	= includes/

HEADER	= minishell.h
SRC = main.c ft_calloc.c ft_split.c ft_substr.c ft_strtrim.c ft_strjoin.c ft_memcpy.c parse.c ft_strncmp.c ft_memmove.c
CFLAGS	= -Wall -Wextra -Werror -g3
OPTIONS	= -I$(SRC_HEADER)
LIBS		= -lreadline

SRCS = $(addprefix $(SRC_PATH),$SRC)
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(SRC_OBJ),$(OBJ))
HEADERS = $(addprefix $(SRC_HEADER),$(HEADER))

CC = @gcc
RM = @rm -rf

$(SRC_OBJ)%.o: $(SRC_PATH)%.c $(HEADERS)
	@mkdir -p $(SRC_OBJ)
	@echo "\033[1;32mCompiling $<\033[0m"  #Ajout de la ligne pour afficher le pourcentage de compilation en couleur.
	$(CC) $(CFLAGS) $(OPTIONS) -o $(@) -c $(<)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LIBS) $(CFLAGS) $(OPTIONS) -o $(@) $(^)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(SRC_OBJ)
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re

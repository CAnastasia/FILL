# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/04 15:13:33 by canastas     #+#   ##    ##    #+#        #
#    Updated: 2018/01/10 05:35:37 by gmadec      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc -O3
CC_FLAGS = -Wall -Werror -Wextra

#******************************************************************************#
#                                    LIBFT                                     #
#******************************************************************************#
NAME_LIBFT = libft.a
PATH_SRC_LIBFT = ./Libft/
PATH_OBJ_LIBFT = ./Libft/
PATH_INC_LIBFT = ./Libft/
FILES_LIBFT = ft_bzero.c ft_fcpy.c ft_list_size.c ft_putchar.c \
			  ft_putendl.c ft_putstr.c ft_puttabstr.c ft_sqrt_next.c \
			  ft_strdup.c ft_strlen.c ft_strsplit.c ft_strsub.c 
OBJ_LIBFT = $(addprefix $(PATH_OBJ_LIBFT), $(FILES_LIBFT:.c=.o))
SRC_LIBFT = $(addprefix $(PATH_SRC_LIBFT), $(FILES_LIBFT))
INC_LIBFT = $(addprefix $(PATH_INC_LIBFT), libft.h)

#******************************************************************************#
#                                   FILLIT                                     #
#******************************************************************************#

NAME = fillit
PATH_SRC_FILLIT = ./Filit/
PATH_OBJ_FILLIT = ./Filit/
PATH_INC_FILLIT = ./Filit/
FILES_FILLIT = ft_check_the_same.c ft_error_tetris0.c  ft_coord.c \
			   ft_replace_up_left.c ft_filling_map.c fillit.c \
			   ft_ltabstrrpl.c ft_lstrsplit_fillittab.c \
			   ft_error_tetris1.c ft_error_tetris2.c
OBJ_FILLIT = $(addprefix $(PATH_OBJ_FILLIT), $(FILES_FILLIT:.c=.o))
SRC_FILLIT = $(addprefix $(PATH_SRC_FILLIT), $(FILES_FILLIT))
INC_FILLIT = $(addprefix $(PATH_INC_FILLIT), fillit.h)

#******************************************************************************#
#                                    ALL                                       #
#******************************************************************************#

all: $(NAME)

#******************************************************************************#
#                             Compilation FILLIT                               #
#******************************************************************************#

$(NAME): $(NAME_LIBFT) $(OBJ_FILLIT)
	@echo "\n\033[1mFILLIT CREATION\n"
	@$(CC) $(CC_FLAGS) $(OBJ_FILLIT) -L ./ -l ft -o $(NAME)
	@echo "   👍  👍  👍 \033[1mFILLIT CREATED\033[0m👍  👍  👍"

$(PATH_OBJ_FILLIT)%.o: $(PATH_SRC_FILLIT)%.c $(INC_FILLIT)
	@echo "0️⃣  Compilation de \033[1m$<\033[0m en \033[1m$@\033[0m"
	@$(CC) $(CC_FLAGS) -o $@ -c $< -I $(PATH_INC_FILLIT)
	@echo "  \033[0;32mCOMPILATION REUSSIE\033[0m\n"

#******************************************************************************#
#                             Compilation LIBFT                                #
#******************************************************************************#

$(NAME_LIBFT): $(OBJ_LIBFT)
	@echo "\n\033[1mLIBFT CREATION\n"
	@ar rcs $(NAME_LIBFT) $(OBJ_LIBFT)
	@echo "  👍  👍  👍 \033[1mLIBFT.A CREATED\033[0m👍  👍  👍\n"

$(PATH_OBJ_LIBFT)%.o: $(PATH_SRC_LIBFT)%.c $(INC_LIBFT)
	@echo "0️⃣  Compilation de \033[1m$<\033[0m en \033[1m$@\033[0m"
	@$(CC) $(CC_FLAGS) -o $@ -c $< -I $(PATH_INC_LIBFT)
	@echo "   \033[0;32mCOMPILATION REUSSIE\033[0m\n"

#******************************************************************************#
#                                   OTHER                                      #
#******************************************************************************#

clean:
	@echo "\n\033[1mCLEAN of .o \n"
	@rm -f $(OBJ_LIBFT) $(OBJ_FILLIT) */.DS_STORE

fclean: clean
	@echo "\n\033[1mFCLEAN $(NAME_LIBFT) AND  $(NAME)\n"
	@rm -f ./Libft/$(NAME_LIBFT) $(NAME_LIBFT) $(NAME) 

re: fclean all

exe: all
	@time ./fillit test.txt

exec: exe fclean

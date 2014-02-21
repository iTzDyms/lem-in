#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cheron <cheron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 17:06:50 by cheron            #+#    #+#              #
#    Updated: 2014/02/21 14:33:55 by cheron           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
CFLAGS = -Wall -Werror -Wextra
OFLAGS = -03
RM = @rm -rf

LIBFT_DIR = ./libft

INCLUDES_DIR = ./libft/includes

LIBFT = $(LIBFT_DIR)/libft.a

NAME = lem-in

OBJ_DIR = obj
SRC_DIR = srcs

SRC = 	main.c \
		ft_getnewlst.c \
		ft_map.c \
		ft_parse.c \
		ft_graph.c \
		ft_isvalid_id.c \
		ft_links.c  \
		ft_links2.c  \
		ft_verif_graph.c \
		ft_resolve.c  \
		ft_resolve2.c  \
		ft_find_ways.c  \
		ft_find_ways2.c  \
		ft_isconform.c	\

OBJ = $(SRC:.c=.o)
POBJ = $(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(LIBFT) $(OBJ_DIR) $(NAME)

$(LIBFT):
	@echo "\nCompilation of objects for "$(LIBFT)
	@($(MAKE) -C $(LIBFT_DIR))

$(NAME): $(POBJ) $(LIBFT)
	@echo "\nLinking "$(NAME)""
	@$(CC) $(CFLAGS) $(OFLAGS) -o $(NAME) $^ \
	-L$(LIBFT_DIR) -lft -I$(INCLUDES_DIR)
	@echo "\n\x1b[32;01mdone!\x1b[0m"

clean:
	@echo "\nCleaning OBJ"
	$(RM) $(POBJ)

fclean: clean
	@echo "\nCleaning "$(NAME)""
	$(RM) $(NAME)
	@($(MAKE) $@ -C $(LIBFT_DIR))

re: fclean all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES_DIR)
	@$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@ -I $(INCLUDES_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

.PHONY: all clean re fclean

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 22:11:31 by huybui            #+#    #+#              #
#    Updated: 2022/02/16 20:34:42 by hbui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

LIBFT_DIR=libft

CC=clang
INCLUDE=-I. -I$(LIBFT_DIR)
LIB=-L$(LIBFT_DIR) -lft
CFLAGS=-Wall -Werror -Wextra

HEADERS=fillit.h
SRCS = movement.c preparation.c print.c solve.c main.c

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT_DIR)/libft.a $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $(SRCS) $(INCLUDE) $(LIB)

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: fclean all

debug: CFLAGS += -g
debug: re

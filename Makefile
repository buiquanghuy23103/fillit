# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 22:11:31 by huybui            #+#    #+#              #
#    Updated: 2022/01/05 00:38:03 by jpikkuma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

LIBFT_DIR=libft

CC=clang
INCLUDE=-I. -I$(LIBFT_DIR)
LIB=-L$(LIBFT_DIR) -lft
CFLAGS=-Wall -Werror -Wextra

SRCS = ft_top.c ft_left.c ft_check_fit.c
SRCS += utils.c preparation.c ft_topleft.c
SRCS += main.c
SRCS += print.c

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT_DIR)/libft.a
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

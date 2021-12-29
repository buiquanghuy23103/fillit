# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 22:11:31 by huybui            #+#    #+#              #
#    Updated: 2021/12/29 21:35:57 by hbui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

LIBFT_DIR=libft
BUILD_DIR=./build

CC=clang
INCLUDE=-I. -I$(LIBFT_DIR)
LIB=-L$(LIBFT_DIR) -lft
CFLAGS=-Wall -Werror -Wextra

SRCS=main.c
OBJS=$(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) -o $@ $< $(INCLUDE) $(LIB)

$(OBJS): $(BUILD_DIR)/%.o :%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(BUILD_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: fclean all

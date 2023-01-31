# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 18:46:49 by hbui-vu           #+#    #+#              #
#    Updated: 2023/01/31 11:47:12 by hbui-vu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c read_map.c draw.c utils.c fdf.c

BSRCS = main.c read_map.c draw.c utils.c keypress.c fdfbonus.c

CC = cc

CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -Ofast -framework OpenGL -g -framework AppKit

LIBFT_DIR = ./libft
MLX_DIR = ./mlx

LIBS = ./libft/libft.a

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

$(NAME): $(OBJS) 
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(LIBS) $(CFLAGS) $(MLX_FLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

bonus: $(NAME) $(BOBJS)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(LIBS) $(MLX_FLAGS) $(BOBJS) -o $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -rf *.o

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

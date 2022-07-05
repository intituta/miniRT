# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 14:37:55 by kferterb          #+#    #+#              #
#    Updated: 2022/07/05 14:37:57 by kferterb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	miniRT

CC				=	gcc
CFLAGC			=	-Wall -Werror -Wextra
RM				=	rm -f

HEADER_DIR		=	inculdes/
SRCS_DIR		=	srcs/

HEADER			=	$(addprefix $(HEADER_DIR),	minirt.h)
MLX				=	-L minilibx -lmlx -framework OpenGL -framework AppKit

SRCS			=	$(addprefix $(SRCS_DIR), errors.c   intersect_cyl.c   main_calls.c    process_elements1.c str_utils.c    vector_operations.c	ft_calloc.c    intersections.c     math_calculs.c      process_elements2.c str_utils2.c	ft_split.c    light_color.c     prepare_to_show.c   read_rt.c     struct_fts.c)

OBJS			=	$(SRCS:%.c=%.o)

.PHONY			:	all clean fclean re

all				:	$(NAME)

$(NAME)			:	$(OBJS)
					@make -C minilibx
					$(CC) $(CFLAGC) $(MLX) $(OBJS) -o $(NAME)

%.o				:	%.c $(HEADER)
					$(CC) $(CFLAGC) -I minilibx mlx -c $< -o $(NAME)

clean			:	
					@make -C minilibx clean
					$(RM) $(OBJS)

fclean			:	clean
					$(RM) $(NAME)

re				:	fclean all
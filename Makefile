# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 12:20:28 by kferterb          #+#    #+#              #
#    Updated: 2022/07/01 11:02:04 by kferterb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	miniRT

CC				=	gcc
CFLAGC			=	-Wall -Werror -Wextra
RM				=	rm -f

HEADER_DIR		=	inculdes/
PARS_DIR		=	parsing/
UTILS_DIR		=	utils/
RAYTRACE_DIR	=	start/

HEADER			=	$(addprefix $(HEADER_DIR),	minirt.h)
MLX				=	-L minilibx -lmlx -framework OpenGL -framework AppKit
LIB				=	-L libft -lft
PARS			=	$(addprefix $(PARS_DIR),		parse_a_c_l.c	parse_sp_pl_cy.c	parse_utils.c	parsing.c)
UTILS			=	$(addprefix $(UTILS_DIR),		gnl.c			split_mod.c		split_utils.c	free.c	../main.c)
RAYTRACE		=	$(addprefix $(RAYTRACE_DIR),	start.c			render.c)

OBJS			=	$(PARS:%.c=%.o) $(UTILS:%.c=%.o) $(RAYTRACE:%.c=%.o)

.PHONY			:	all clean fclean re

all				:	$(NAME)

$(NAME)			:	$(OBJS)
					@make -C libft
					@make -C minilibx
					$(CC) $(CFLAGC) $(LIB) $(MLX) $(OBJS) -o $(NAME)

%.o				:	%.c $(HEADER)
					$(CC) $(CFLAGC) -I minilibx mlx -c $< -o $(NAME)

clean			:	
					@make -C libft clean
					@make -C minilibx clean
					$(RM) $(OBJS)

fclean			:	clean
					@make -C libft fclean
					$(RM) $(NAME)

re				:	fclean all
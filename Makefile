# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 12:20:28 by kferterb          #+#    #+#              #
#    Updated: 2022/06/01 16:19:00 by kferterb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_HEADERS		= ./includes/

DIR_SRCS		= ./srcs/

SRC				= utils/error_exit.c \
				  geometry/vector.c \
				  scene/camera.c scene/scene.c \
				  figures/sphere.c \
				  ray_tracing/ray_trace.c \
				  intersections/sphere_intersect.c \
				  main.c \

SRCS			= $(addprefix $(DIR_SRCS), $(SRC))

OBJS			= $(SRCS:.c=.o)

NAME			= miniRT

LIBMLX			= libmlx.dylib

GCC				= gcc

RM				= rm -f

CFLAGS			= -Wall -Werror -Wextra

%.o: %.c
				$(GCC) $(CFLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(NAME):		$(OBJS)
				make -C ./minilibx_mms_20200219
				cp ./minilibx_mms_20200219/libmlx.dylib .
				$(GCC) $(CFLAGS) -I $(DIR_HEADERS) $(LIBMLX) $(OBJS) -o $(NAME)

all:			$(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				make clean -C ./minilibx_mms_20200219
				$(RM) $(LIBMLX)
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re

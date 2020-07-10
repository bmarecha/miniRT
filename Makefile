
SRCS	=	gnl/get_next_line.c \
			gnl/get_next_line_utils.c \
			minifiles/minirt.c \
			minifiles/addforms.c \
			minifiles/splitrt.c \
			minifiles/addambiant.c \
			minifiles/utilsrt.c \
			minifiles/ft_atof.c

OBJS	=	${SRCS:.c=.o}

NAME	=	miniRT

MLX		=	libmlx.dylib

MLXDIR = minilibx_mms_20200219/

LIBFT = libft/libft.a

.c.o	:
	gcc -Wall -Werror -Wextra -Ilibft/ -c $< -o ${<:.c=.o}

all     :   ${NAME}

$(MLX)	:
	make -C ${MLXDIR}

$(LIBFT) :
	make -C libft/

$(NAME)	:	${OBJS} ${LIBFT}
	gcc ${OBJS} -Ilibft/ -Llibft/ -lft -o ${NAME}

clean	:
	rm -f ${OBJS}
	make clean -C ${MLXDIR}
	make clean -C libft/

fclean	:	clean
	rm -f ${NAME}

re		: fclean all 

.PHONY	: all clean fclean re

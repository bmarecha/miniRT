
SRCS	=	gnl/get_next_line.c \
			gnl/get_next_line_utils.c \
			minifiles/miniRT.c \
			minifiles/ft_split.c \
			minifiles/addforms.c \
			minifiles/addambiant.c

OBJS	=	${SRCS:.c=.o}

NAME	=	miniRT

MLX		=	libmlx.dylib

MLXDIR = minilibx_mms_20200219/

.c.o	:
	gcc -Wall -Werror -Wextra -Iincludes/ -c $< -o ${<:.c=.o}

all     :   ${NAME} #${MLX} ${NAME}

${MLX}	:
	make -C ${MLXDIR}

$(NAME)	:	${OBJS}
	gcc ${OBJS} -o ${NAME}
	#gcc ${OBJS} -I${MLXDIR} -L${MLXDIR} -lmlx -o ${NAME}

clean	:
	rm -f ${OBJS}
	make clean -C ${MLXDIR}

fclean	:	clean
	rm -f ${NAME}

re		: fclean all 

.PHONY	: all clean fclean re

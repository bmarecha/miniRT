SRCS	=	gnl/get_next_line.c \
			gnl/get_next_line_utils.c \
			minifiles/minirt.c \
			minifiles/addforms.c \
			minifiles/splitrt.c \
			minifiles/addambiant.c \
			minifiles/utilsrt.c \
			minifiles/ft_atof.c \
			minifiles/windowmanager.c 

OBJS	=	${SRCS:.c=.o}

NAME	=	miniRT

#MLXDIR = minilibx_mms_20200219/
MLXDIR = minilibx_opengl_20191021/

MLX		=	libmlx.a

LIBFT = libft/libft.a

.c.o	:
	gcc -Wall -Werror -Wextra -I${MLXDIR} -Ilibft/ -c $< -o ${<:.c=.o}

all     :   ${NAME}

$(MLX)	:
	make -C ${MLXDIR}
	cp ${MLXDIR}/${MLX} ./

$(LIBFT) :
	make -C libft/

$(NAME)	:	${OBJS} ${LIBFT} ${MLX}
	gcc ${OBJS} -I${MLXDIR} -Ilibft/ -L${MLXDIR} -lmlx -Llibft/ -lft -o ${NAME}

clean	:
	rm -f ${OBJS}
	rm -f ${MLX}
	make clean -C ${MLXDIR}
	make clean -C libft/

fclean	:	clean
	rm -f ${NAME}

re		: fclean all 

.PHONY	: all clean fclean re

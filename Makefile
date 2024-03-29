SRCS	=	gnl/get_next_line.c \
			gnl/get_next_line_utils.c \
			minifiles/minirt.c \
			minifiles/forms/addforms.c \
			minifiles/forms/create_forms.c \
			minifiles/forms/intersphere.c \
			minifiles/forms/intercyl.c \
			minifiles/splitrt.c \
			minifiles/addambiant.c \
			minifiles/utilsrt.c \
			minifiles/windowmanager.c \
			minifiles/drawing.c \
			minifiles/vect.c \
			minifiles/rayons.c \
			minifiles/raylight.c \
			minifiles/forms/interplane.c \
			minifiles/isometries.c \
			minifiles/create_bmp.c \
			minifiles/utilsray.c \
			minifiles/utilsraycolor.c \
			minifiles/utilsraycolor2.c

OBJS	=	${SRCS:.c=.o}

NAME	=	miniRT

#MLXDIR = minilibx_mms_20200219/
MLXDIR = minilibx-linux/

MLX	= ${MLXDIR}libmlx.a

LIBFT = libft/libft.a

INCLUDES = -Ilibft/ \
	   -I${MLXDIR} \
	   -I/usr/include \
	   -Iminifiles/

INCLIB = -L/usr/lib \
	 -Llibft/ \
	 -L${MLXDIR}

LIBS = -lft -lmlx -lXext -lX11 -lm -lbsd

.c.o	:
	gcc -Wall -Werror -Wextra -c $< ${INCLUDES} -o ${<:.c=.o}

all     :   ${NAME}

$(MLX)	:
	make -C ${MLXDIR}

$(LIBFT) :
	make re -C libft/

$(NAME)	: ${LIBFT} ${MLX} ${OBJS}
	gcc -g -o ${NAME} ${INCLIB} ${OBJS} ${LIBS}

clean	:
	rm -f ${OBJS}
	make clean -C ${MLXDIR}
	make clean -C libft/

fclean	:	clean
	make fclean -C libft/
	rm -f ${MLX}
	rm -f ${NAME}

re		: fclean all 

.PHONY	: all clean fclean re

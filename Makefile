
SRCS	=	miniRT.c

OBJS	=	${SRCS:.c=.o}

NAME	=	miniRT

.c.o	:
	gcc -Wall -Werror -Wextra -Iincludes/ -c $< -o ${<:.c=.o}

$(NAME)	:	${OBJS}
	gcc -o ${NAME} ${OBJS}

all		:	${NAME}

clean	:
	rm -f ${OBJS} 

fclean	:	clean
	rm -f ${NAME}

re		: fclean all 

.PHONY	: all clean fclean re

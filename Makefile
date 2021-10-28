NAME = fdf
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f
SRCS = srcs/main.c srcs/ft_itoa.c

OBJC = ${SRCS:.c=.o}

all: ${NAME}
	
${NAME}: ${OBJC}
	$(CC) ${CFLAGS} -lmlx -framework OpenGL -framework AppKit ${OBJC} -o $(NAME)
	
clean:
	 ${RM} ${OBJC}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

CC=gcc
CFLAGS= -Wall -Wextra -Werror
NAME= fdf
SRCS =  srcs/main.c srcs/ft_draw_line.c \
		srcs/get_next_line.c srcs/ft_check_file.c \
		srcs/ft_parse_file.c srcs/ft_projec_iso.c \
		srcs/ft_draw_map.c srcs/ft_error.c \
		srcs/ft_event.c srcs/ft_gen_point.c
OBJS = ${SRCS:.c=.o}
LFLAGS = -lmlx

UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	#mac
	LFLAGS += -framework OpenGL -framework AppKit
else
	#Linux and others...
	INC=/usr/include
	INCLIB=${INC}../lib
	CFLAGS += -I${INC} -O3 -I.. -g
	LFLAGS += -L.. -L${INCLIB} -lXext -lX11 -lm -no-pie -lbsd
endif

all: ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C ./libft
	${CC} ${OBJS} ${LFLAGS} ./libft/libft.a -o ${NAME}

fclean: clean
	${MAKE} clean -C ./libft
	rm -f ${NAME}

clean:
	${MAKE} fclean -C ./libft
	rm -f ${NAME} ${OBJS}

re: fclean clean all

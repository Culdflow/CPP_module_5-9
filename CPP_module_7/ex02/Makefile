CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address -g
# -fsanitize=address
NAME = Array
CFILES = main.cpp \

OBJS = ${CFILES:.cpp=.o}

.cpp.o:
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	$(CC) ${CFLAGS} $(OBJS) -o $(NAME)

fclean:	clean
	rm -rf ${NAME}

clean:
	rm -rf ${OBJS}

re:	fclean all

.PHONY: all clean fclean re
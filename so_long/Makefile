SRC = 

OBJ = $(SRC:.c = .o)

CC = cc 
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME} : ${OBJ} 
	ar -rcs ${NAME} ${OBJ}

clean:
	rm -f ${OBJ}

fclean:
	rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re
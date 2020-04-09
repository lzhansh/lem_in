NAME = libft.a

FLAGS = -Wall -Werror -Wextra
SRCS = *.c
HDRS = libft.h
OBJ = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME):
	gcc $(FLAGS) -I . $(HDRS) -c $(SRCS)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all
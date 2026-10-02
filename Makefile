CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
NAME := libft.a
OBJECTS := $(patsubst %.c, %.o, $(wildcard *.c))

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f ./*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OBJECTS): %.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

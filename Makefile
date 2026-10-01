CC := cc
CFLAGS := -g3
NAME := libft.a
OBJECTS := $(patsubst %.c, %.o, $(wildcard *.c))

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f ./*.o

fclean: clean
	rm $(NAME)

re: fclean $(NAME)

$(OBJECTS): %.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

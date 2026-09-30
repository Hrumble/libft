CC := cc
ARGS := -g3
NAME := libft.a
# OBJECTS = ft_atoi.c ft_isascii.c ft_memcpy.c ft_strlcat.c ft_strrchr.c libft.h ft_bzero.c ft_isdigit.c ft_memmove.c ft_strlcpy.c ft_substr.c ft_calloc.c ft_isprint.c ft_memset.c ft_strlen.c ft_tolower.c ft_isalnum.c ft_memchr.c ft_strchr.c ft_strncmp.c ft_toupper.c ft_isalpha.c ft_memcmp.c ft_strdup.c ft_strnstr.c libft.a
OBJECTS := $(patsubst %.c, %.o, $(wildcard *.c))

all: $(NAME) clean

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

fclean: clean
	rm $(NAME)

clean:
	rm -f ./*.o

$(OBJECTS): %.o: %.c
	$(CC) $(ARGS) -c $^ -o $@

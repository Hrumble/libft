*This project has been created as part of the 42 curriculum by ngero.*

# Description
Libft is a library containing tools and functions that will be useful throughout the 42 cursus. The goal is to build a
library that we will be able to link in following projects.

# Instructions
Make the library using the Makefile with:
```sh
$ make
```
To clean all of the leftover object files, use `make clean`, you can also remove everything + the library using `make
fclean`. 
you can then compile a project by linking libft with:
```sh
$ cc -Wall -Wextra -Werror my_code.c -L. -lft
```

If for any reason you must redo the entire process, consider `make re`

# Resources
A.I. Has not been used within this project.

# Library
The functions included in this library are the following:
## Character functions
- `ft_isalnum.c`
- `ft_isalpha.c`
- `ft_isascii.c`
- `ft_isdigit.c`
- `ft_isprint.c`
## Memory Manipulation
- `ft_memchr.c`
- `ft_memcmp.c`
- `ft_memcpy.c`
- `ft_memmove.c`
- `ft_memset.c`
- `ft_bzero.c`
- `ft_calloc.c`
## Integers and Ascii
- `ft_atoi.c`
- `ft_itoa.c`
## Linked Lists
- `ft_lstadd_back.c`
- `ft_lstadd_front.c`
- `ft_lstclear.c`
- `ft_lstdelone.c`
- `ft_lstiter.c`
- `ft_lstlast.c`
- `ft_lstmap.c`
- `ft_lstnew.c`
- `ft_lstsize.c`
## Strings
- `ft_strchr.c`
- `ft_strdup.c`
- `ft_striteri.c`
- `ft_strjoin.c`
- `ft_strlcat.c`
- `ft_strlcpy.c`
- `ft_strlen.c`
- `ft_strmapi.c`
- `ft_strncmp.c`
- `ft_strnstr.c`
- `ft_strrchr.c`
- `ft_strtrim.c`
- `ft_substr.c`
- `ft_split.c`
- `ft_tolower.c`
- `ft_toupper.c`
## Put functions
- `ft_putstr_fd.c`
- `ft_putchar_fd.c`
- `ft_putendl_fd.c`
- `ft_putnbr_fd.c`

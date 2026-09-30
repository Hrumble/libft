#include "../libft.h"
#include <stdio.h>

void	debug_print(void *s, size_t len)
{
	while (len--)
	{
		if (ft_isprint(*(char *)s))
			printf("%c", *(char *)s);
		else
			printf("\\%x", *(char *)s);
		s++;
	}
	printf("\n");
}

int main()
{
	printf("%lu\n", ft_strlen("Hello"));
	debug_print(ft_strjoin("Hello", " World."), 15);
}

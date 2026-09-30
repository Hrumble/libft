#include "../libft.h"
#include <stddef.h>
#include <stdio.h>

void	debug_print(void *s, size_t len)
{
	while (len--)
	{
		if (ft_isprint(*(char *)s) && *(char *)s != ' ')
			printf("%c", *(char *)s);
		else
			printf("\\%x", *(char *)s);
		s++;
	}
	printf("\n");
}

void	print_str_arr(char **arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		printf(" | ");
		debug_print(arr[size], ft_strlen(arr[size]));
		if (i == size - 1)
			printf(" | ");
		i++;
	}
}

void	print_err(void *expected, void *actual, size_t len1, size_t len2)
{
	printf("[ERROR]\n");
	printf("Expected: ");
	debug_print(expected, len1);
	printf("Got: ");
	debug_print(actual, len2);
}

int	assert_eq_str(char *s1, char *s2)
{
	size_t	lens1;
	size_t	lens2;

	if (s1 == s2)
		return (1);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (lens1 != lens2)
		return (print_err(s2, s1, lens2, lens1), 0);
	if (ft_strncmp(s1, s2, lens1))
		return (print_err(s2, s1, lens2, lens1), 0);
	return (1);
}

int	assert_eq_strarr(char **a1, char **a2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (!assert_eq_str(a1[i], a2[i]))
		{
			print_str_arr(a1, size);
			return (0);
		}
		i++;
	}
	return (1);
}

void test__ft_strjoin()
{
	printf("====		FT_STRJOIN		====\n");
	{
		assert_eq_str(ft_strjoin("Hello", " World."), "Hello World.");
		assert_eq_str(ft_strjoin("", ""), "");
	}
	{
		char *str1 = "Hello man, eat shit";
		char *str2 = str1 + 9;
		assert_eq_str(ft_strjoin(str1, str2), "Hello man, eat shit, eat shit");
	}
	printf("[DONE]\n");
}

void	test__ft_substr()
{
	printf("====		FT_SUBSTR		====\n");
	{
		assert_eq_str(ft_substr("Hello World.", 0, 5), "Hello");
		assert_eq_str(ft_substr("Hello World.", 6, 5), "World");
	}
	printf("[DONE]\n");
}

void	test__ft_strtrim()
{
	printf("====		FT_STRTRIM		====\n");
	{
		assert_eq_str(ft_strtrim("    Hello World.     ", " "), "Hello World.");
		assert_eq_str(ft_strtrim("--==**Motherfudger**==--", "-=*"), "Motherfudger");
		assert_eq_str(ft_strtrim("Motherfudger**==--", "-=*"), "Motherfudger");
		assert_eq_str(ft_strtrim("Motherfudger", "-=*"), "Motherfudger");
		assert_eq_str(ft_strtrim("Motherfudger", ""), "Motherfudger");
		assert_eq_str(ft_strtrim("", "-"), "");
		assert_eq_str(ft_strtrim("-|En|shit|ifi-cation|-", "-|"),
				"En|shit|ifi-cation");
		assert_eq_str(ft_strtrim("Hello World", "Hedl"),
				"o Wor");
	}
	printf("[DONE]\n");
}

void	test__ft_split()
{
	printf("====		FT_SPLIT		====\n");
	{
		assert_eq_strarr(ft_split("Hello World.", ' '), (char *[]){"Hello", "World.", 0}, 3);
		assert_eq_strarr(ft_split("   Hello       World. ", ' '), (char *[]){"Hello", "World.", 0}, 3);
		assert_eq_strarr(ft_split("   Hello       World.  ", ' '), (char *[]){"Hello", "World.", 0}, 3);
		assert_eq_strarr(ft_split("okwhat", ' '), (char *[]){"okwhat", 0}, 2);
		assert_eq_strarr(ft_split("", ' '), (char *[]){0}, 1);
	}
}

int main()
{
	test__ft_strjoin();
	test__ft_substr();
	test__ft_strtrim();
	test__ft_split();
	printf("[DONE]\n");
}


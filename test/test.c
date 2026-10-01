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
	printf("====	FT_STRJOIN	====\n");
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
	printf("====	FT_SUBSTR	====\n");
	assert_eq_str(ft_substr("Hello World.", 0, 5), "Hello");
	assert_eq_str(ft_substr("Hello World.", 6, 5), "World");
	printf("[DONE]\n");
}

void	test__ft_strtrim()
{
	printf("====	FT_STRTRIM	====\n");
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
	printf("[DONE]\n");
}

void	test__ft_split()
{
	printf("====	FT_SPLIT	====\n");
	assert_eq_strarr(ft_split("Hello World.", ' '), (char *[]){"Hello", "World.", 0}, 3);
	assert_eq_strarr(ft_split("   Hello       World. ", ' '), (char *[]){"Hello", "World.", 0}, 3);
	assert_eq_strarr(ft_split("   Hello       World.  ", ' '), (char *[]){"Hello", "World.", 0}, 3);
	assert_eq_strarr(ft_split("okwhat", ' '), (char *[]){"okwhat", 0}, 2);
	assert_eq_strarr(ft_split("", ' '), (char *[]){0}, 1);
	printf("[DONE]\n");
}

void	test__ft_itoa()
{
	printf("====	FT_ITOA		====\n");
	assert_eq_str(ft_itoa(-4567), "-4567");
	assert_eq_str(ft_itoa(-5), "-5");
	assert_eq_str(ft_itoa(75921), "75921");
	assert_eq_str(ft_itoa(2), "2");
	assert_eq_str(ft_itoa(0), "0");
	assert_eq_str(ft_itoa(2147483647), "2147483647");
	assert_eq_str(ft_itoa(-2147483648), "-2147483648");
	printf("[DONE]\n");
}

char	strmapi_upper(unsigned int i, char c)
{
	return ft_toupper(c + (i - i));
}

char	strmapi_weird(unsigned int i, char c)
{
	if (i%2 == 0)
		return ft_toupper(c);
	return c;
}

void	test__ft_strmapi()
{
	printf("====	FT_STRMAPI	====\n");
	assert_eq_str(ft_strmapi("hey nice man.", strmapi_upper), "HEY NICE MAN.");
	assert_eq_str(ft_strmapi("hey nice man.", strmapi_weird), "HeY NiCe mAn.");
	printf("[DONE]\n");
}

void	striteri_upper(unsigned int i, char *c)
{
	*c = ft_toupper(*c + (i - i));
}

void	striteri_weird(unsigned int i, char *c)
{
	if (i%2 == 0)
		*c = ft_toupper(*c + (i - i));
}

void	test__ft_striteri()
{
	printf("====	FT_STRITERI	====\n");
	{
		char str[] = "hey nice man.";
		ft_striteri(str, striteri_upper);
		assert_eq_str(str, "HEY NICE MAN.");
	}
	{
		char str[] = "hey nice man.";
		ft_striteri(str, striteri_weird);
		assert_eq_str(str, "HeY NiCe mAn.");
	}
	printf("[DONE]\n");
}

void	test_ft_putnbr_fd()
{
	printf("====	FT_putnbr_fd	====\n");
	ft_putstr_fd("0: ", 1);
	ft_putnbr_fd(0, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("1000: ", 1);
	ft_putnbr_fd(1000, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("2147483647: ", 1);
	ft_putnbr_fd(2147483647, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("-2147483648: ", 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("1000: ", 1);
	ft_putnbr_fd(1000, 2);
	ft_putchar_fd('\n', 1);
	printf("[DONE]\n");
	
}

int main()
{
	test__ft_strjoin();
	test__ft_substr();
	test__ft_strtrim();
	test__ft_split();
	test__ft_itoa();
	test__ft_strmapi();
	test__ft_striteri();
	test_ft_putnbr_fd();
	printf("============================\n");
	printf("[DONE]\n");
}


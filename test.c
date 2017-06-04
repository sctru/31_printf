/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:47:25 by tchan             #+#    #+#             */
/*   Updated: 2017/01/20 17:35:32 by tchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	test_funct(char *str, ...)
{
	char	*string;
	va_list	var_list;
	int x = 0;

	va_start(var_list, str);
	string = va_arg(var_list, char*);
	while(string != NULL)
	{	
		printf("%s\n", string);
		string = va_arg(var_list, char*);
		if(string == NULL)
			printf("nulled");
	}
	va_end(var_list);
}

int main (int argc, char **argv)
{
	// struct lconv * lc;
	// setlocale(LC_MONETARY, "en_US");
	// lc = localeconv();
	// lc->thousands_sep;
	//test_funct("123", "234", "345");	
	// char *test = "axe";
	// char c = 'x';
	// printf("%+ 10d", c);
	//printf("%hhd", c);
	//char	*test = "12345";
	//char	*test2 = "909090";
	// int		tint = 0;
	// size_t	ull =  2147483648;
	// size_t	ull2 = 9294967299;
	// printf("123%nzu, %zu\n", &tint, ull2);
	// printf("%zu", (unsigned long)tint);
	// printf("%hhd\n", c);
	// printf("%hd\n", x);
	// printf("%ld\n", y);
	// printf("%lld\n", z);
	// printf("%jd\n", y);
	// printf("%zd\n", 123);
	// printf("d%+.5d d%010d\n", (int)z, x);
	// printf("i%-+10i i% 10i\n", (int)z, x);
	t_params test;

	test.modifier = 0;

	char	*string = "123456789";
	char	*string2 = "abcdefghijklmn";
	short x = 62;
	long y = 987;
	long long z = 10451;
	unsigned long ul = 711;
	char c = 'c';
	int a = 070;
	unsigned int b = 0xFFFFFF;
	int g = 2147483648;

	ft_putui_base(b, 16, 1);
	ft_putui_base(b, 16, 0);
}

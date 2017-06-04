/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_import2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchan <tchan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 23:09:24 by tchan             #+#    #+#             */
/*   Updated: 2017/06/03 23:09:32 by tchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_strncmp(char *str1, char *str2, size_t size)
{
	unsigned long x;

	x = 0;
	if (size == 0)
		return (0);
	while (*str1 && (*str1 == *str2) && x < size)
	{
		str1++;
		str2++;
		x++;
	}
	if (x == size)
		return ((unsigned)*(str1 - 1)) - ((unsigned char)*(str2 - 1));
	return ((unsigned char)*str1 - (unsigned char)*str2);
}

int	ft_numlength(long number)
{
	int neg_flag;
	int count;

	count = 0;
	neg_flag = 0;
	if(number < 0)
		neg_flag = 1;
	while(number != 0)
	{
		number /= 10;
		count++;
	}
	if(neg_flag)
		return (count + 1);
	return (count);
}

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int			simple_atoi(char *str)
{
	int x;
	int count;
	
	count = 0;
	x = 0;

	while (ft_isdigit(str[x]))
	{
		count = count * 10 + (str[x] - '0');
		x++;
	}
	return (count);
}

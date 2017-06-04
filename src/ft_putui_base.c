/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putui_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchan <tchan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 20:42:40 by tchan             #+#    #+#             */
/*   Updated: 2017/06/03 20:42:42 by tchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

/* only handles negatives in decimal (base 10)...*/
/* not normed */
/* memory leaks 2x */

void	ft_putui_base(unsigned int num, unsigned int base, int cap)
{
	const char		*basestr[2] = {"0123456789ABCDEF", "0123456789abcdef"};

	if(base == 0)
		return ;
	if (num >= base)
	{
		ft_putui_base(num / base, base, cap);
		ft_putchar(basestr[cap][(num % base)]);
	}
	if (num < base)
		ft_putchar(basestr[cap][(num % base)]);
}

static char	*rev_str(char *str)
{
	int x = 0;
	int y = 0;
	while (str[x] != '\0')
		x++;
	char *tmp = (char *)malloc(sizeof(char) * (x + 1));
	while(x-- > 0)
		tmp[y++] = str[x];
	tmp[y] = '\0';
	free (str);
	return (tmp);
}

static char	base_char(int val, int base)
{
	if (base > 9 && val > 9)
		return (val - 10 + 'A');
	if(val < base && val < 0)
	{
		if (base > 9 && val < -9)
			return (-val - 10 + 'A');
		return (-val + '0');
	}
	return (val + '0');
}

char	*ft_itoa_base(int value, int base)
{
	long x = value;
	int	length = 0;
	int neg_flag = 0;
	char *ret;

	if (base == 10 && value < 0)
		neg_flag = 1;
	while (x /= base)
		length++;
	ret = (char *)malloc(sizeof(char) * (length + 1));
	if(value == 0)
		ret[x++] = '0';
	while(value != 0)
	{
		ret[x++] = base_char(value % base, base);
		value /= base;
	}
	if(neg_flag)
		ret[x++] = '-';
	ret[x] = '\0';
	return  (rev_str(ret));
}

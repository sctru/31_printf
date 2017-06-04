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

#include "libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putui_base(unsigned long num, unsigned int base, int cap, t_params *params)
{
	const char		*basestr[2] = {"0123456789ABCDEF", "0123456789abcdef"};
	const char		*hexhead[2] = {"0X", "0x"};

	if(params->pound_flag == 1)
	{
		if(base == 8 && num != 0)
			ft_putchar('0');
		else if(base == 16)
			ft_putstr(hexhead[cap]);
		params->pound_flag = 0;
	}
	if(base == 0)
		return ;
	if (num >= base)
	{
		ft_putui_base(num / base, base, cap, params);
		ft_putchar(basestr[cap][(num % base)]);
	}
	if (num < base)
		ft_putchar(basestr[cap][(num % base)]);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	if (n < 10)
		ft_putchar(n % 10 + '0');
}

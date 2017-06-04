/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchan <tchan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 19:26:17 by tchan             #+#    #+#             */
/*   Updated: 2017/06/03 19:26:30 by tchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		print_char(t_params *params, va_list var_list)
{
	char c;

	if(params->modifier == 4)
	{
		print_wchar(params, var_list);
		return ;
	}	
	c = va_arg(var_list, int);
	ft_putchar(c);
	params->printed = 1;
}

void		print_wchar(t_params *params, va_list var_list)
{
	// char w;

	// w = va_arg(var_list, int);
	// ft_putchar(w);

	int		c;
	char	wc[4];
	size_t	index;

	c = va_arg(var_list, int);
	index = 0;
	wc[3] = (c >= 0x000000FF && ++index) ? (128 + c % 64) : c;
	if (index == 1)
	{
		c = c >> 6;
		wc[2] = (c >= 0x00000040 && ++index) ? ((128 + c % 64)) : (192 + c % 32);
	}
	if (index == 2)
	{
		c = c >> 6;
		wc[1] = (c >= 0x00000010 && ++index) ? ((128 + c % 64)) : (224 + c);
	}
	if (index == 3)
	{
		c = c >> 6;
		wc[0] = (240 + c);
	}
	write(1, &wc[3 - index], index + 1);
	params->printed = 1;
}

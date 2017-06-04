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
		print_wchar(params, var_list, 0, 0);
		return ;
	}	
	c = va_arg(var_list, int);
	ft_putchar(c);
	params->printed = 1;
}

void		print_wchar(t_params *params, va_list var_list, int flag, int c_in)
{
	char	*str;
	int		c;

	if(flag == 0)
		c = va_arg(var_list, int);
	else
		c = c_in;
	str = ft_strnew(4);
	if (c <= 0x7F)
		str[0] = c;
	else if (c <= 0x7FF)
	{
		str[0] = (c >> 6) + 0xc0;
		str[1] = (c & 0x3f) + 0x80;
	}
	else if (c <= 0xFFFF)
	{
		str[0] = (c >> 12) + 0xe0;
		str[1] = ((c >> 6) & 0x3f) + 0x80;
		str[2] = (c & 0x3f) + 0x80;
	}
	else if (c <= 0x10FFFF)
	{
		str[0] = (c >> 18) + 0xf0;
		str[1] = (c >> 12 & 0x3f) + 0x80;
		str[2] = (c >> 6 & 0x3f) + 0x80;
		str[3] = (c & 0x3f) + 0xc80;
	}
	ft_putstr(str);

	params->printed = 1;
}


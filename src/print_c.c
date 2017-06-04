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

	c = va_arg(var_list, int);
	if(params->modifier == 4)
	{
		print_wchar(params, var_list);
		return ;
	}	
	ft_putchar(c);
	params->printed = 1;
}

void		print_wchar(t_params *params, va_list var_list)
{
	wchar_t w;

	w = va_arg(var_list, wchar_t);
	ft_putchar((char)w);
	params->printed = 1;
}

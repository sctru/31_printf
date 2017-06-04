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
	char w;

	w = va_arg(var_list, int);
	ft_putchar(w);
	params->printed = 1;
}

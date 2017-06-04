/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchan <tchan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:44:12 by tchan             #+#    #+#             */
/*   Updated: 2017/06/03 16:44:29 by tchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	pad_uint(t_params *params, int count, unsigned int num)
{
	if((params->plus_flag == 1 || params->space_flag == 1) && num > 0)
		count--;
	if(params->minus_flag == 1)
	{
		if(params->plus_flag == 1 && num > 0)
			ft_putchar('+');
		if(params->space_flag == 1 && num > 0)
			ft_putchar(' ');
		ft_putui_base(num, 10, 0, params);
		print_fill(params, count);
	}
	else
	{
		if(params->plus_flag == 1 && num > 0)
			ft_putchar('+');
		if(params->space_flag == 1 && num > 0)
			ft_putchar(' ');
		print_fill(params, count);
		ft_putui_base(num, 10, 0, params);
	}
}

void			print_uint_b10(t_params *params, va_list var_list)
{
	int				len;
	unsigned int	num;

	num = grab_uint(params, var_list);
	len = ft_base_numlength(num, 10);
	if(!(num == 0 && params->precision_flag == 1 && params->precision == 0))
	{
		if(params->width > len)
		pad_uint(params, params->width - len, num);
		else
		{
		if(params->plus_flag == 1 && num > 0)
			ft_putchar('+');
		else if(params->space_flag == 1 && num > 0)
			ft_putchar(' ');
		ft_putui_base(num, 10, 0, params);
		}
	}
	params->printed = 1;
}
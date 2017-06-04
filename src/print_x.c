/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchan <tchan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 15:35:08 by tchan             #+#    #+#             */
/*   Updated: 2017/06/03 15:35:20 by tchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	pad_hex(t_params *params, int count, unsigned int num)
{
	if((params->plus_flag == 1 || params->space_flag == 1) && num > 0)
		count--;
	if(params->minus_flag == 1)
	{
		if(params->plus_flag == 1 && num > 0)
			ft_putchar('+');
		if(params->space_flag == 1 && num > 0)
			ft_putchar(' ');
		ft_putui_base(num, 16, 0);
		print_fill(params, count);
	}
	else
	{
		if(params->plus_flag == 1 && num > 0)
			ft_putchar('+');
		if(params->space_flag == 1 && num > 0)
			ft_putchar(' ');
		print_fill(params, count);
		ft_putui_base(num, 16, 0);
	}
}

void	print_uint_hex(t_params *params, va_list var_list, int cap)
{
	int				len;
	unsigned int	num;

	num = grab_uint(params, var_list);
	len = ft_base_numlength(num, 16);
	if(!(num == 0 && params->precision_flag == 1 && params->precision == 0))
	{
		if(params->width > len)
		pad_hex(params, params->width - len, num);
		else
		{
			if(params->plus_flag == 1 && num > 0)
				ft_putchar('+');
			else if(params->space_flag == 1 && num > 0)
				ft_putchar(' ');
			ft_putui_base(num, 16, cap);
		}
	}
	params->printed = 1;
}
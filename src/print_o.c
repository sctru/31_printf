/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchan <tchan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 13:12:12 by tchan             #+#    #+#             */
/*   Updated: 2017/06/03 13:12:24 by tchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned int	grab_uint(t_params *params, va_list var_list)
{
	unsigned int	num;

	num = 0;
	if (params->modifier == 1)
		num = va_arg(var_list, int);
	else if (params->modifier == 2)
		num = va_arg(var_list, int);
	else if (params->modifier == 3)
		num = va_arg(var_list, long long);
	else if (params->modifier == 4)
		num = va_arg(var_list, long);
	else if (params->modifier == 5)
		num = va_arg(var_list, long long);
	else if (params->modifier == 6)
		num = va_arg(var_list, unsigned long);
	else
		num = va_arg(var_list, unsigned int);
	return (num);
}

void			pad_oct(t_params *params, int count, unsigned int num)
{
	if ((params->plus_flag == 1 || params->space_flag == 1) && num > 0)
		count--;
	if (params->minus_flag == 1)
	{
		if (params->plus_flag == 1 && num > 0)
			ft_putchar('+');
		if (params->space_flag == 1 && num > 0)
			ft_putchar(' ');
		ft_putui_base(num, 8, 0, params);
		print_fill(params, count);
	}
	else
	{
		if (params->plus_flag == 1 && num > 0)
			ft_putchar('+');
		if (params->space_flag == 1 && num > 0)
			ft_putchar(' ');
		print_fill(params, count);
		ft_putui_base(num, 8, 0, params);
	}
}

void			print_uint_oct(t_params *params, va_list var_list)
{
	unsigned int	num;
	size_t			len;

	num = grab_uint(params, var_list);
	len = ft_base_numlength(num, 8);
	if (!(num == 0 && params->precision_flag == 1 && params->precision == 0))
	{
		if (params->width > len)
			pad_oct(params, params->width - len, num);
		else
		{
			if (params->plus_flag == 1 && num > 0)
				ft_putchar('+');
			else if (params->space_flag == 1 && num > 0)
				ft_putchar(' ');
			ft_putui_base(num, 8, 0, params);
		}
	}
	params->printed = 1;
}

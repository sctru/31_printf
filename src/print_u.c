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

void				pad_uint(t_params *params, int count, unsigned int num)
{
	if ((params->plus_flag == 1 || params->space_flag == 1) && num > 0)
		count--;
	if (params->minus_flag == 1)
	{
		if (params->plus_flag == 1 && num > 0)
			ft_putchar('+');
		if (params->space_flag == 1 && num > 0)
			ft_putchar(' ');
		ft_putui_base(num, 10, 0, params);
		print_fill(params, count);
	}
	else
	{
		if (params->plus_flag == 1 && num > 0)
			ft_putchar('+');
		if (params->space_flag == 1 && num > 0)
			ft_putchar(' ');
		print_fill(params, count);
		ft_putui_base(num, 10, 0, params);
	}
}

void				put_big_unum(unsigned long long num)
{
	if (num >= 10)
	{
		put_big_number(num / 10);
		ft_putchar(num % 10 + '0');
	}
	if (num < 10)
		ft_putchar(num % 10 + '0');
}

unsigned long long	pull_big_unum(t_params *params, va_list var_list)
{
	unsigned long long num;

	num = 0;
	if (params->modifier == 3)
		num = va_arg(var_list, unsigned long long);
	else if (params->modifier == 4)
		num = va_arg(var_list, unsigned long);
	else if (params->modifier == 5)
		num = va_arg(var_list, unsigned long long);
	else if (params->modifier == 6)
		num = va_arg(var_list, unsigned long);
	else
		num = va_arg(var_list, int);
	return (num);
}

void				print_big_uint(t_params *params, va_list var_list)
{
	unsigned long long num;

	num = pull_big_unum(params, var_list);
	put_big_unum(num);
	params->printed = 1;
}

void				print_uint_b10(t_params *params, va_list var_list)
{
	int				len;
	unsigned int	num;

	if (params->modifier > 2)
	{
		print_big_uint(params, var_list);
		return ;
	}
	num = grab_uint(params, var_list);
	len = ft_base_numlength(num, 10);
	if (!(num == 0 && params->precision_flag == 1 && params->precision == 0))
	{
		if (params->width > len)
			pad_uint(params, params->width - len, num);
		else
		{
			if (params->plus_flag == 1 && num > 0)
				ft_putchar('+');
			else if (params->space_flag == 1 && num > 0)
				ft_putchar(' ');
			ft_putui_base(num, 10, 0, params);
		}
	}
	params->printed = 1;
}

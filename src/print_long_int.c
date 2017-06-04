/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchan <tchan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 07:43:13 by tchan             #+#    #+#             */
/*   Updated: 2017/06/04 07:43:14 by tchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	put_big_number(long long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		put_big_number(n / 10);
		ft_putchar(n % 10 + '0');
	}
	if (n < 10)
		ft_putchar(n % 10 + '0');
}

long long	pull_big_number(t_params *params, va_list var_list)
{
	long long num;

	num = 0;
	if(params->modifier == 3)
		num = va_arg(var_list, long long);
	else if(params->modifier == 4)
		num = va_arg(var_list, long);
	else if(params->modifier == 5)
		num = va_arg(var_list, long long);
	else if(params->modifier == 6)
		num = va_arg(var_list, unsigned long);
	else
		num = va_arg(var_list, int);
	return (num);
}

void		print_big_int(t_params *params, va_list var_list)
{
	long long	num;
	int			len;
	
	num = pull_big_number(params, var_list);
	len = ft_base_numlength(num, 10);

	put_big_number(num);
	params->printed = 1;
}

void	print_int_wp(t_params *params, int num, int len)
{
	
	if(params->precision > params->width && params->precision > len)
	{
		params->zero_flag = 1;
		params->minus_flag = 0;
		if(params->space_flag && num > 0)
			ft_putchar(' ');
		if(params->plus_flag && num > 0)
			ft_putchar('+');
		params->space_flag = 0;
		params->plus_flag = 0;
		pad_int(params, params->precision - len, num);
	}
	else if(params->width > params->precision && params->width > len)
	{
		if(params->precision > len)
			if(params->minus_flag)
			{
				params->minus_flag = 0;
				params->zero_flag = 1;
				pad_int(params, params->precision - len, num);
				string_fill(' ', params->width - params->precision);
			}
			else
			{	
				string_fill(' ', params->width - params->precision);
				pad_int(params, params->precision - len, num);
			}
		else
		{
			params->zero_flag = 0;
			pad_int(params, params->width - len, num);
		}
	}
	else if(params->precision == params->width)
	{
		if(params->precision > len)
			pad_int(params, params->precision, num);
		else
			ft_putnbr(num);
	}
	else
		ft_putnbr(num);
	params->printed = 1;
}


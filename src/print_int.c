/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchan <tchan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:02:57 by tchan             #+#    #+#             */
/*   Updated: 2017/06/02 14:03:06 by tchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		grab_number(t_params *params, va_list var_list)
{
	int	num;
	
	num = 0;
	if(params->modifier == 1)
		num = va_arg(var_list, int);
	else if(params->modifier == 2)
		num = va_arg(var_list, int);
	else if(params->modifier == 3)
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


void	print_fill(t_params *params, int count)
{
	int		x;
	char	c;
	
	x = 0;
	c = ' ';
	if(params->zero_flag == 1)
		c = '0';
	while(x++ < count)
		write(1, &c, 1);
}

void	pad_int(t_params *params, int count, int num)
{
	if((params->plus_flag == 1 || params->space_flag == 1) && num > 0)
		count--;
	if(params->minus_flag == 1)
	{
		if(params->plus_flag == 1 && num > 0)
			ft_putchar('+');
		if(params->space_flag == 1 && num > 0)
			ft_putchar(' ');
		ft_putnbr(num);
		print_fill(params, count);
	}
	else
	{
		if(params->plus_flag == 1 && num > 0)
			ft_putchar('+');
		if(params->space_flag == 1 && num > 0)
			ft_putchar(' ');
		print_fill(params, count);
		ft_putnbr(num);
	}
}

void	print_int(t_params *params, va_list var_list)
{
	int	len;
	int	num;

	num = grab_number(params, var_list);
	len = ft_base_numlength(num, 10);
	if(!(num == 0 && params->precision_flag == 1 && params->precision == 0))
	{
		if(params->precision_flag && params->width_flag)
		{
			print_int_wp(params, num, len);
			params->printed = 1;
			return ;
		}
		if(params->width > len)
		pad_int(params, params->width - len, num);
		else
		{
		if(params->plus_flag == 1 && num > 0)
			ft_putchar('+');
		else if(params->space_flag == 1 && num > 0)
			ft_putchar(' ');
		ft_putnbr(num);
		}
	}
	params->printed = 1;
}

void	print_int_wp(t_params *params, int num, int len)
{
	
	if(params->precision > params->width && params->precision > len)
	{
		params->zero_flag = 1;
		params->minus_flag = 0;
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
}




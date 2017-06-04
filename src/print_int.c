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

void	print_int(t_params *params, va_list var_list, char type)
{
	int	len;
	int	num;
	
	if(type == 'D' && params->modifier == 0)
		params->modifier = 3;
	if(params->modifier > 2)
	{
		print_big_int(params, var_list);
		return ;
	}
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






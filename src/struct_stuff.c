/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchan <tchan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:09:16 by tchan             #+#    #+#             */
/*   Updated: 2017/05/31 15:09:22 by tchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_struct(t_params *params)
{
	params->printed = 0;
	params->modifier = 0;
	params->width = 0;
	params->precision_flag = 0;
	params->precision = 0;
	params->pound_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;
	params->space_flag = 0;
	params->plus_flag = 0;
}

void	debug_struct(t_params params)
{
	printf("\nprinted: %d\n", params.printed);
	printf("modifier: %d\n", params.modifier);
	printf("width: %d\n", params.width);
	printf("precision: %d\n", params.precision);
	printf("precision flag: %d\n", params.precision_flag);
	printf("pound: %d\nzero: %d\nminus: %d\nspace: %d\nplus: %d\n",params.pound_flag, params.zero_flag, params.minus_flag, params.space_flag, params.plus_flag);
}

int		lflag_check(char **str, t_params *params)
{
	if(**str == 'h')
		params->modifier = 2;
	else if(**str == 'l')
		params->modifier = 4;
	else if(**str == 'j')
		params->modifier = 5;
	else if(**str == 'z')
		params->modifier = 6;
	if(ft_strlen(*str) >= 2)
	{
		if(ft_strncmp(*str, "hh", 2) == 0)
		{
			params->modifier = 1;
			(*str)++;
		}
		if(ft_strncmp(*str, "ll", 2) == 0)
		{
			params->modifier = 3;
			(*str)++;
		}
	}
	return (0);
}

int		flag_check(char **str, t_params *params)
{
	if(**str == '#')
		params->pound_flag = 1;	
	else if(**str == '0')
		params->zero_flag = 1;
	else if(**str == '-')
		params->minus_flag = 1;
	else if(**str == '+')
		params->plus_flag = 1;
	else if(**str == ' ')
		params->space_flag = 1;
	lflag_check(str, params);
	return (0);
}

void		other_check(char **str, t_params *params, va_list var_list)
{
	if(**str > '0' && **str <= '9')
	{
		params->width = simple_atoi(*str);
		(*str) += ft_numlength(params->precision);
	}
	if(**str == '*')
		params->width = va_arg(var_list, int);
	if(**str == '.')
	{
		if((int)ft_strlen(*str) > 1)
		{
			if(*(*str + 1) == '*')
			{	
				params->precision = va_arg(var_list, int);
				(*str)++;
			}
			else
			{
				(*str)++;
				params->precision = simple_atoi(*str);
				(*str) += ft_numlength(params->precision) - 1;
			}
		}
		params->precision_flag = 1;
	}
	flag_check(str, params);
}
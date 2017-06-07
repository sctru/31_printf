/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:48:35 by tchan             #+#    #+#             */
/*   Updated: 2017/01/11 14:48:36 by tchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	parse_helper(char **str, t_params *params, va_list var_list)
{
	if (**str == 's')
		print_string(params, var_list);
	else if (**str == 'S')
		print_string(params, var_list);
	else if (**str == 'p')
		print_pointer(params, var_list);
	else if (**str == 'i' || **str == 'd' || **str == 'D')
		print_int(params, var_list, **str);
	else if (**str == 'o' || **str == 'O')
		print_uint_oct(params, var_list);
	else if (**str == 'u' || **str == 'U')
		print_uint_b10(params, var_list);
	else if (**str == 'x')
		print_uint_hex(params, var_list, 1);
	else if (**str == 'X')
		print_uint_hex(params, var_list, 0);
	else if (**str == 'c')
		print_char(params, var_list);
	else if (**str == 'C')
		print_wchar(params, var_list, 0, 0);
	else if (**str == '%')
		print_percent(params);
	else
		flag_check(str, params, var_list);
}

int		parse_string(char **str, va_list var_list)
{
	t_params	params;

	params.printed = 0;
	init_struct(&params);
	(*str)++;
	while (**str != '\0' && params.printed == 0)
	{
		parse_helper(str, &params, var_list);
		(*str)++;
	}
	return (0);
}

void	ft_printf(char *str, ...)
{
	va_list	var_list;

	va_start(var_list, str);
	if (error_check(str, var_list))
		error_check(str, var_list);
	va_end(var_list);
	va_start(var_list, str);
	while (*str != '\0')
	{
		if (*str == '%')
			parse_string(&str, var_list);
		else
			write(1, str++, 1);
	}
	va_end(var_list);
}

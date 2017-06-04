/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchan <tchan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:14:03 by tchan             #+#    #+#             */
/*   Updated: 2017/05/31 14:14:12 by tchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	string_fill(char c, int len)
{
	int x;

	x = 0;
	while (x++ < len)
		ft_putchar(c);
}

void	part_string(char *str, int len)
{
	int x;

	x = 0;
	while (x < len && str[x] != '\0')
		ft_putchar(str[x++]);
}

void	print_string(t_params *params, va_list var_list)
{
	int		len;
	char	*str;

	str = va_arg(var_list, char*);
	len = ft_strlen(str);
	if (params->minus_flag)
	{
		if (params->precision < len && params->precision_flag)
		{
			part_string(str, params->precision);
			if (params->width > len)
				string_fill(' ', params->width - params->precision);
		}
		else
			ft_putstr(str);
	}
	else
	{
		if (params->precision < len && params->precision_flag)
			len = params->precision;
		if (params->width > len)
			string_fill(' ', params->width - len);
		part_string(str, len);
	}
	params->printed = 1;
}

void	print_wstring(t_params *params, va_list var_list)
{
	wchar_t *wstr;

	wstr = va_arg(var_list, wchar_t*);
	while (*wstr)
	{
		print_wchar(params, var_list, 1, *wstr++);
		(wstr)++;
	}
	params->printed = 1;
}

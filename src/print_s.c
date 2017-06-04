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

void	string_fill(char c, char *str, int len)
{
	int x;

	x = 0;
	while(x < len)
		str[x++] = c;
}

void	print_string(t_params *params, va_list var_list)
{
	int		len;
	char	*str;
	char	*buff;
	char	*tmp;
	
	tmp = NULL;
	str = va_arg(var_list, char*);
	len = ft_strlen(str);
	if(params->precision < len)
	{
		buff = ft_strnew(len);
		str = ft_strncpy(buff, str, len);
		len = params->precision;
		free(buff);
	}
	if(params->width > len)
	{
		buff = ft_strnew(params->width - len);
		string_fill(' ', buff, params->width - len);
		if(params->minus_flag)
			tmp = ft_strjoin(str, buff);
		else
			tmp = ft_strjoin(buff, str);
		free(buff);
	}
	if(tmp == NULL)
		ft_putstr(str);
	else
		ft_putstr(tmp);
	params->printed = 1;
}

void	print_wstring(t_params *params, va_list var_list)
{
	/* read va_args with wint_t, get size of wchar_t. Save as char *str, put str */
	wchar_t *wstr;

	wstr = va_arg(var_list, wchar_t*);
	ft_putstr((char*)wstr);
	params->printed = 1;
}
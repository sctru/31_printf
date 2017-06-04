/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchan <tchan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 15:49:14 by tchan             #+#    #+#             */
/*   Updated: 2017/06/02 16:05:20 by tchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_pointer(t_params *params, va_list var_list)
{
	unsigned long stor;

	stor = va_arg(var_list, unsigned long);
	ft_putstr(ft_itoa_base(stor, 16));
	params->printed = 1;
}

void	print_percent(t_params *params)
{
	ft_putchar('%');
	params->printed = 1;
}

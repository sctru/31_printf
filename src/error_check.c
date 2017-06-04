/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchan <tchan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:13:38 by tchan             #+#    #+#             */
/*   Updated: 2017/05/31 14:13:39 by tchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		error_check(char *str, va_list var_list)
{
	str = va_arg(var_list, char *);
	if (str == NULL)
		return (1);
	return (0);
}

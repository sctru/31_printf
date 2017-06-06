/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_numlength.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchan <tchan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 13:25:02 by tchan             #+#    #+#             */
/*   Updated: 2017/06/03 13:25:17 by tchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_base_numlength(long number, int base)
{
	int neg_flag;
	int count;

	if (base == 0)
		return (1);
	count = 0;
	neg_flag = 0;
	if (number < 0)
		neg_flag = 1;
	while (number != 0)
	{
		number /= base;
		count++;
	}
	if (neg_flag)
		return (count + 1);
	return ((size_t)count);
}

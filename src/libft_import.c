/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_import.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchan <tchan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 22:54:05 by tchan             #+#    #+#             */
/*   Updated: 2017/06/03 22:54:14 by tchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(const char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned long	x;

	x = 0;
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (x < size + 1)
	{
		str[x] = '\0';
		x++;
	}
	return (str);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	int x;

	x = 0;
	while (src[x] != '\0' && x < (int)n)
	{
		dest[x] = src[x];
		x++;
	}
	while (x < (int)n)
	{
		dest[x] = '\0';
		x++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	x = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	str = (char *)malloc(sizeof(char) * (x + y + 1));
	if (!str)
		return (NULL);
	x = 0;
	while (s1[x] != '\0')
	{
		str[x] = s1[x];
		x++;
	}
	while (s2[y] != '\0')
	{
		str[x + y] = s2[y];
		y++;
	}
	str[x + y] = '\0';
	return (str);
}

void	ft_putstr(char const *str)
{
	int x;

	x = 0;
	if (str == NULL)
		return ;
	while (str[x] != '\0')
	{
		ft_putchar(str[x]);
		x++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchan <tchan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 15:43:32 by tchan             #+#    #+#             */
/*   Updated: 2017/06/04 15:43:34 by tchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_params
{
	char		printed;
	char		modifier;
	char		width_flag;
	int			width;
	char		precision_flag;
	int			precision;
	char		pound_flag;
	char		zero_flag;
	char		minus_flag;
	char		space_flag;
	char		plus_flag;
}				t_params;
void			ft_printf(char *str, ...);
void			init_struct(t_params *param_table);
void			debug_struct(t_params params);
int				arg_count_check(va_list list, char *str);

void			other_check(char **str, t_params *params, va_list var_list);
void			flag_check(char **str, t_params *params, va_list var_list);
int				parse_string(char **str, va_list var_list);
int				error_check(char *str, va_list var_list);

void			string_fill(char c, int len);
void			print_int_wp(t_params *params, int num, int len);
void			pad_int(t_params *params, int count, int num);
void			print_fill(t_params *params, int count);
int				grab_number(t_params *params, va_list var_list);
int				ft_base_numlength(long number, int base);
void			print_big_int(t_params *params, va_list var_list);
void			put_big_number(long long n);
long long		grab_big_num(t_params *params, va_list var_list);

unsigned int	grab_uint(t_params *params, va_list var_list);
void			ft_putui_base(\
unsigned long n, unsigned int b, int c, t_params *p);

void			print_string(t_params *params, va_list var_list);
void			print_wstring(t_params *params, va_list var_list);
void			print_pointer(t_params *params, va_list var_list);
void			print_decimal(t_params *params, va_list var_list);
void			print_int(t_params *params, va_list var_list, char type);
void			print_uint_oct(t_params *params, va_list var_list);
void			print_uint_b10(t_params *params, va_list var_list);
void			print_uint_hex(t_params *params, va_list var_list, int cap);
void			print_char(t_params *params, va_list var_list);
void			print_wchar(t_params *params, va_list var_list, \
int flag, int c_in);
void			print_percent(t_params *params);

size_t			ft_strlen(const char *str);
char			*ft_strnew(size_t size);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_putstr(char const *str);
int				ft_strncmp(char *str1, char *str2, size_t size);
int				ft_numlength(long number);
int				simple_atoi(char *str);
void			ft_putchar(char c);
void			ft_putnbr(long n);

#endif

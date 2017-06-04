/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 13:28:56 by tchan             #+#    #+#             */
/*   Updated: 2017/02/15 13:28:58 by tchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_params
{
	char		printed;
	/* modifiers: 1-hh 2-h 3-ll 4-l 5-j 6-z */
	char		modifier;
	int			width;
	int			precision_flag;
	int			precision;
	char		pound_flag;
	char		zero_flag;
	char		minus_flag;
	char		space_flag;
	char		plus_flag;
// data pointer??  void		*ptr;
}				t_params;

void			ft_printf(char *str, ...);
void			init_struct(t_params *param_table);
void			debug_struct(t_params params);
int				arg_count_check(va_list list, char *str);
/* parsing, interpreting functions */
void			other_check(char **str, t_params *params, va_list var_list);
int				parse_string(char **str, va_list var_list);
int				error_check(char* str, va_list var_list);
/*string helper functions */
void			string_fill(char c, char *str, int len);
/*int helper functions */
int				b_trim(int num, int base, int trimto);
void			print_fill(t_params *params, int count);
int				grab_number(t_params *params, va_list var_list);
int				ft_base_numlength(long number, int base);
/*unsigned int helper functions */
unsigned int	grab_uint(t_params *params, va_list var_list);
void			ft_putui_base(unsigned int num, unsigned int base, int cap);

/* top level print functions */
void			print_string(t_params *params, va_list var_list);
void			print_wstring(t_params *params, va_list var_list);
void			print_pointer(t_params *params, va_list var_list);
void			print_decimal(t_params *params, va_list var_list);
void			print_int(t_params *params, va_list var_list);
void			print_uint_oct(t_params *params, va_list var_list);
void			print_uint_b10(t_params *params, va_list var_list);
void			print_uint_hex(t_params *params, va_list var_list, int cap);
void			print_char(t_params *params, va_list var_list);
void			print_wchar(t_params *params, va_list var_list);
void			print_percent(t_params *params);

#endif
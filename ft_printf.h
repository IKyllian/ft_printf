/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:40:28 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/28 15:32:40 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct	s_struct
{
	int			has_neg;
	int			has_zero;
	int			len_field;
	int			len_is_neg;
	int			has_dot;
	int			dot_val;
	int			has_star;
	int			neg_print;
	char		type;
}				t_flags;

int				ft_printf(const char *format, ...);
void			ft_putchar(char c, int *count);
void			ft_putnbr(int n, int *count);
void			ft_unsigned_putnbr(unsigned int n, int *count);
void			ft_putstr(char *str, int *count);
void			ft_itoh(unsigned long nbr, int low, int *count, t_flags *flgs);
int				nbr_length(int nbr);
int				u_nbr_len(unsigned long nbr, unsigned int size_base);
int				ft_atoi(char *nptr);
int				ft_strlen(const char *s);

int				is_conversions(char c);
void			struct_initialize(t_flags *flags);
void			to_decimal(va_list list, int *count, t_flags *flags);
void			to_unsigned_decimal(va_list list, int *count, t_flags *flags);
void			to_hexa(va_list list, int *count, int is_min, t_flags *flags);
void			to_character(va_list list, int *count, t_flags *flags);
void			to_pointer_address(va_list list, int *count, t_flags *flags);
void			to_string(va_list list, int *count, t_flags flags);
void			to_percent(int *count, t_flags *flags);

void			fill_space(char c, int size, int *count);

void			ope_dot_address(t_flags *f, int *count, int arg, int *len);
void			ope_dot(t_flags *f, int *count, int arg, int *len);
void			ope_space(t_flags *flags, int *c, int arg, int *len);
void			ope_space_suff(t_flags *flags, int *count, int arg, int len);
void			print_neg(int arg, int *count, t_flags *flags, int *arg_len);

void			operands_string_dot(t_flags flags, int *count, char *str);
void			ope_space_string(t_flags flags, int *count, char *str);
void			ope_space_string_suff(t_flags flags, int *count, char *str);
void			print_string(t_flags flags, int *count, char *str);

void			check_space_is_neg(t_flags *flags);

#endif

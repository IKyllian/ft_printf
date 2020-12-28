/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_and_conversions2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:37:48 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/28 15:03:01 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_conversions(char c)
{
	if (c == 's' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' ||
		c == 'c' || c == '%' || c == 'p')
		return (1);
	else
		return (0);
}

void	struct_initialize(t_flags *flags)
{
	flags->has_neg = 0;
	flags->len_field = 0;
	flags->len_is_neg = 0;
	flags->has_dot = 0;
	flags->dot_val = 0;
	flags->has_zero = 0;
	flags->has_star = 0;
	flags->neg_print = 0;
	flags->type = 0;
}

void	check_space_is_neg(t_flags *flags)
{
	if (flags->len_field < 0)
	{
		if (!flags->has_dot)
			flags->has_neg = 1;
		flags->len_field *= -1;
		flags->len_is_neg = 1;
	}
	if (flags->dot_val < 0)
	{
		flags->has_neg = 1;
		flags->dot_val *= -1;
	}
}

void	to_percent(int *count, t_flags *flags)
{
	check_space_is_neg(flags);
	//if (flags->has_dot && !flags->dot_val && !flags->len_field)
	//	return ;
	ope_dot(flags, count, 1, 1);
	ope_space(flags, count, 1, 1);
	ft_putchar('%', count);
	ope_space_suff(flags, count, 1, 1);
}

void	to_character(va_list list, int *count, t_flags *flags)
{
	int	nbr;

	check_space_is_neg(flags);
	nbr = va_arg(list, int);
	if (nbr == 0 && flags->has_dot && !flags->dot_val && !flags->len_field)
		return ;
	ope_dot(flags, count, 1, 1);
	ope_space(flags, count, 1, 1);
	ft_putchar(nbr, count);
	ope_space_suff(flags, count, 1, 1);
}

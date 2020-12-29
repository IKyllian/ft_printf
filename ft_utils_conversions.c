/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_conversions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:36:40 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/28 16:43:51 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	to_string(va_list list, int *count, t_flags flags)
{
	char *str;

	check_space_is_neg(&flags);
	str = va_arg(list, char *);
	if (!str)
		str = "(null)";
	operands_string_dot(flags, count, str);
	ope_space_string(flags, count, str);
	print_string(flags, count, str);
	ope_space_string_suff(flags, count, str);
}

void	to_decimal(va_list list, int *count, t_flags *flags)
{
	int nbr;
	int	arg_len;

	check_space_is_neg(flags);
	nbr = va_arg(list, int);
	arg_len = nbr_length(nbr);
	if (nbr == 0 && flags->has_dot && !flags->dot_val && !flags->len_field)
		return ;
	ope_dot(flags, count, nbr, &arg_len);
	ope_space(flags, count, nbr, &arg_len);
	if (nbr == 0 && ((flags->dot_val && !flags->len_field) ||
		(flags->len_is_neg && !flags->has_star)))
		ft_putchar(' ', count);
	else
		ft_putnbr(nbr, count);
	ope_space_suff(flags, count, nbr, arg_len);
}

void	to_unsigned_decimal(va_list list, int *count, t_flags *flags)
{
	unsigned long	nbr;
	int				arg_len;

	check_space_is_neg(flags);
	nbr = (unsigned int)va_arg(list, int);
	arg_len = u_nbr_len(nbr, 10);
	if (nbr == 0 && flags->has_dot && !flags->dot_val && !flags->len_field)
		return ;
	ope_dot(flags, count, 1, &arg_len);
	ope_space(flags, count, 1, &arg_len);
	if (nbr == 0 && ((flags->dot_val && !flags->len_field) ||
		(flags->len_is_neg && !flags->has_star)))
		ft_putchar(' ', count);
	else
		ft_unsigned_putnbr(nbr, count);
	ope_space_suff(flags, count, 1, arg_len);
}

void	to_hexa(va_list list, int *count, int is_min, t_flags *flags)
{
	unsigned long	nbr;
	int				arg_len;

	check_space_is_neg(flags);
	nbr = (unsigned int)va_arg(list, int);
	arg_len = u_nbr_len(nbr, 16);
	if (nbr == 0 && flags->has_dot && !flags->dot_val && !flags->len_field)
		return ;
	ope_dot(flags, count, 1, &arg_len);
	ope_space(flags, count, 1, &arg_len);
	if (nbr == 0 && flags->dot_val && !flags->len_field)
		ft_putchar(' ', count);
	else
		ft_itoh(nbr, is_min, count, flags);
	ope_space_suff(flags, count, 1, arg_len);
}

void	to_pointer_address(va_list list, int *count, t_flags *flags)
{
	void	*input;
	int		neg_p;
	int		arg_len;

	check_space_is_neg(flags);
	neg_p = 1;
	input = (void *)va_arg(list, void *);
	arg_len = u_nbr_len((unsigned long)input, 16) + 2;
	if ((unsigned long)input == 0 && flags->has_dot &&
		!flags->dot_val && !flags->len_field)
		return ;
	ope_dot_address(flags, count, 1, &arg_len);
	ope_space(flags, count, 1, &arg_len);
	print_neg((unsigned long)input, count, flags, &arg_len);
	ft_itoh((unsigned long)input, 1, count, flags);
	ope_space_suff(flags, count, 1, arg_len);
}

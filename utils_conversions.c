/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_conversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:36:40 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/22 12:46:10 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	to_string(va_list list, int *count, t_struct flags)
{
	char *str;
	int space_is_neg;

	space_is_neg = 0;
	if (flags.dot_value < 0)
	{
		flags.has_negative = 1;
		flags.dot_value *= -1;
		space_is_neg = 1;
	}
	if (flags.has_multiple < 0)
	{
		flags.has_negative = 1;
		flags.has_multiple *= -1;
		space_is_neg = 1;
	}
	str = va_arg(list, char *);
	if (!str)
		str = "(null)";
	operands_string_dot(flags, count);
	operands_spaces_string_prefix(flags, count, str);
	print_string(flags, count, str, space_is_neg);
	operands_spaces_string_suffix(flags, count, str);
}

void	to_decimal(va_list list, int *count, t_struct flags)
{
	int nbr;
	
	nbr = va_arg(list, int);
	if (nbr == 0 && flags.has_dot && !flags.dot_value && (!flags.spaces_number && !flags.has_multiple))
		return ;
	operands_dot(flags, count, nbr, nbr_length(nbr));
	operands_spaces_prefix(flags, count, nbr, nbr_length(nbr));
	if (nbr == 0 && flags.dot_value && (!flags.spaces_number && !flags.has_multiple))
		ft_putchar(' ', count);
	else
		ft_putnbr(nbr, count);
	operands_spaces_suffix(flags, count, nbr, nbr_length(nbr));
}

void	to_unsigned_decimal(va_list list, int *count, t_struct flags)
{
	unsigned int	nbr;

	nbr = va_arg(list, unsigned int);
	if (nbr == 0 && flags.has_dot && !flags.dot_value && (!flags.spaces_number && !flags.has_multiple))
		return ;
	operands_dot(flags, count, nbr, nbr_length(nbr));
	operands_spaces_prefix(flags, count, nbr, nbr_length(nbr));
	if (nbr == 0 && flags.dot_value && (!flags.spaces_number && !flags.has_multiple))
		ft_putchar(' ', count);
	else
		ft_unsigned_putnbr(nbr, count);
	operands_spaces_suffix(flags, count, nbr, nbr_length(nbr));
}

void	to_hexa(va_list list, int *count, int is_min, t_struct flags)
{
	unsigned long long nbr;
	
	nbr = (unsigned int)va_arg(list, int);
	if (nbr == 0 && flags.has_dot && !flags.dot_value && (!flags.spaces_number && !flags.has_multiple))
		return ;
	operands_dot(flags, count, nbr, nbr_length_hexa(nbr));
	operands_spaces_prefix(flags, count, nbr, nbr_length_hexa(nbr));
	ft_putstr(ft_itoh2(nbr, is_min), count);
	operands_spaces_suffix(flags, count, nbr, nbr_length_hexa(nbr));

}

void	to_character(va_list list, int *count, t_struct flags)
{
	int	nbr;

	nbr = va_arg(list, int);
	if (nbr == 0 && flags.has_dot && !flags.dot_value && (!flags.spaces_number && !flags.has_multiple))
		return ;
	operands_dot(flags, count, nbr, 1);
	operands_spaces_prefix(flags, count, nbr, 1);
	ft_putchar(nbr, count);
	operands_spaces_suffix(flags, count, nbr, 1);
}

void	to_pointer_address(va_list list, int *count, t_struct flags)
{

	void *input;

	input = va_arg(list, void *);
	if ((int)input == 0 && flags.has_dot && !flags.dot_value && (!flags.spaces_number && !flags.has_multiple))
		return ;
	operands_dot(flags, count, (int)input, nbr_length_hexa((unsigned long)input));
	operands_spaces_prefix(flags, count, (int)input, nbr_length_hexa((unsigned long)input));
	ft_putstr(ft_itoh((unsigned long)(int)input), count);
	operands_spaces_suffix(flags, count, (int)input, nbr_length_hexa((unsigned long)input));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_conversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:36:40 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/22 15:53:36 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_space_is_neg(t_struct *flags)
{
	if (flags->spaces_number < 0)
	{
		
		if (!flags->has_dot)
			flags->has_negative = 1;
		flags->spaces_number *= -1;
		flags->spaces_is_neg = 1;
	}
	if (flags->dot_value < 0)
	{
		flags->has_negative = 1;
		flags->dot_value *= -1;
	}
}

void	to_string(va_list list, int *count, t_struct flags)
{
	char *str;

	check_space_is_neg(&flags);
	str = va_arg(list, char *);
	if (!str)
		str = "(null)";
	operands_string_dot(flags, count, str);
	operands_spaces_string_prefix(flags, count, str);
	print_string(flags, count, str);
	operands_spaces_string_suffix(flags, count, str);
}

void	to_decimal(va_list list, int *count, t_struct flags)
{
	int nbr;
	int neg_is_print;
	
	check_space_is_neg(&flags);
	neg_is_print = 0;
	nbr = va_arg(list, int);
	if (nbr == 0 && flags.has_dot && !flags.dot_value && !flags.spaces_number)
		return ;
	operands_dot(flags, count, nbr, nbr_length(nbr), &neg_is_print);
	operands_spaces_prefix(flags, count, nbr, nbr_length(nbr), &neg_is_print);
	if (nbr == 0 && flags.dot_value && !flags.spaces_number)
		ft_putchar(' ', count);
	else
		ft_putnbr(nbr, count);
	operands_spaces_suffix(flags, count, nbr, nbr_length(nbr));
}

void	to_unsigned_decimal(va_list list, int *count, t_struct flags)
{
	unsigned long	nbr;
	int neg_is_print;

	check_space_is_neg(&flags);
	neg_is_print = 1;
	nbr = (unsigned int)va_arg(list, int);
	if (nbr == 0 && flags.has_dot && !flags.dot_value && !flags.spaces_number)
		return ;
	operands_dot(flags, count, 1, u_nbr_length(nbr), &neg_is_print);
	operands_spaces_prefix(flags, count, 1, u_nbr_length(nbr), &neg_is_print);
	if (nbr == 0 && flags.dot_value && !flags.spaces_number)
		ft_putchar(' ', count);
	else
		ft_unsigned_putnbr(nbr, count);
	operands_spaces_suffix(flags, count, 1, u_nbr_length(nbr));
}

void	to_hexa(va_list list, int *count, int is_min, t_struct flags)
{
	unsigned long nbr;
	int neg_is_print;

	check_space_is_neg(&flags);
	neg_is_print = 1;
	nbr = (unsigned int)va_arg(list, int);
	if (nbr == 0 && flags.has_dot && !flags.dot_value && !flags.spaces_number)
		return ;
	operands_dot(flags, count, 1, nbr_length_hexa(nbr), &neg_is_print);
	operands_spaces_prefix(flags, count, 1, nbr_length_hexa(nbr), &neg_is_print);
	if (nbr == 0 && flags.dot_value && !flags.spaces_number)
		ft_putchar(' ', count);
	else
		ft_putstr(ft_itoh2(nbr, is_min), count);
	operands_spaces_suffix(flags, count, 1, nbr_length_hexa(nbr));

}

void	to_character(va_list list, int *count, t_struct flags)
{
	int	nbr;
	int neg_is_print;

	check_space_is_neg(&flags);
	neg_is_print = 1;
	nbr = va_arg(list, int);
	if (nbr == 0 && flags.has_dot && !flags.dot_value && !flags.spaces_number)
		return ;
	operands_dot(flags, count, 1, 1, &neg_is_print);
	operands_spaces_prefix(flags, count, 1, 1, &neg_is_print);
	ft_putchar(nbr, count);
	operands_spaces_suffix(flags, count, 1, 1);
}

void	to_pointer_address(va_list list, int *count, t_struct flags)
{
	void *input;
	int neg_is_print;

	check_space_is_neg(&flags);
	neg_is_print = 1;
	input = (void *)va_arg(list, void *);
	if ((unsigned long)input == 0 && flags.has_dot && !flags.dot_value && !flags.spaces_number)
		return ;
	operands_dot(flags, count, 1, nbr_length_hexa((unsigned long)input) + 2, &neg_is_print);
	operands_spaces_prefix(flags, count, 1, nbr_length_hexa((unsigned long)input) + 2, &neg_is_print);
	ft_putstr(ft_itoh((unsigned long)input), count);
	operands_spaces_suffix(flags, count, 1, nbr_length_hexa((unsigned long)input) + 2);
}

void	to_percent(int *count, t_struct flags)
{
	int neg_is_print;

	check_space_is_neg(&flags);
	neg_is_print = 1;
	//if (flags.has_dot && !flags.dot_value && !flags.spaces_number)
	//	return ;
	operands_dot(flags, count, 1, 1, &neg_is_print);
	operands_spaces_prefix(flags, count, 1, 1, &neg_is_print);
	ft_putchar('%', count);
	operands_spaces_suffix(flags, count, 1, 1);
}
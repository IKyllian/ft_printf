/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_conversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:36:40 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/15 15:29:02 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	to_string(va_list list, int *count, int prefix, char c_pre, int suffix)
{
	char *str;

	str = va_arg(list, char *);
	if (prefix && !suffix)
		ft_fill_space(c_pre, (prefix - ft_strlen(str)), count);
	if (str)
		ft_putstr(str, count);
	if (suffix)
		ft_fill_space(' ', (prefix - ft_strlen(str)), count);
}

void	to_decimal(va_list list, int *count, int prefix, char c_pre, int suffix)
{
	int nbr;

	nbr = va_arg(list, int);
	if (prefix && !suffix)
		ft_fill_space(c_pre, (prefix - nbr_length(nbr)), count);
	ft_putnbr(nbr, count);
	if (suffix)
		ft_fill_space(' ', (prefix - nbr_length(nbr)), count);
}

void	to_unsigned_decimal(va_list list, int *count, int prefix, char c_pre, int suffix)
{
	unsigned int nbr;

	nbr = va_arg(list, unsigned int);
	if (prefix && !suffix)
		ft_fill_space(c_pre, (prefix - nbr_length(nbr)), count);
	ft_putnbr((int)nbr, count);
	if (suffix)
		ft_fill_space(c_pre, (prefix - nbr_length(nbr)), count);
}

void	to_hexa(va_list list, int *count, int is_min, int prefix, char c_pre, int suffix)
{
	int nbr;

	nbr = va_arg(list, int);
	if (prefix && !suffix)
		ft_fill_space(c_pre, (prefix - nbr_length_hexa(nbr)), count);
	ft_putstr(ft_itoh2(nbr, is_min), count);
	if (suffix)
		ft_fill_space(c_pre, (prefix - nbr_length_hexa(nbr)), count);
}

void	to_character(va_list list, int *count, int prefix, char c_pre, int suffix)
{
	int nbr;

	nbr = va_arg(list, int);
	if (prefix)
		ft_fill_space(c_pre, (prefix - 1), count);
	ft_putchar(nbr, count);
	if (suffix)
		ft_fill_space(c_pre, (prefix - 1), count);
}

void	to_pointer_address(va_list list, int *count, int prefix, char c_pre, int suffix)
{
	void *input;

	input = va_arg(list, void *);
	if (prefix)
		ft_fill_space(c_pre, (prefix - (nbr_length_hexa((unsigned long)input) +2)), count);
	ft_putstr(ft_itoh((unsigned long)input), count);
	if (suffix)
		ft_fill_space(c_pre, (prefix - nbr_length_hexa((unsigned long)input)), count);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_conversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:36:40 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/14 18:24:51 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	to_string(va_list list, int *count, int prefix, char c_pre)
{
	char *str;

	str = va_arg(list, char *);
	if (prefix)
		ft_fill_space(c_pre, (prefix - ft_strlen(str)), count);
	if (str)
		ft_putstr(str, count);
}

void	to_decimal(va_list list, int *count, int prefix, char c_pre)
{
	int nbr;

	nbr = va_arg(list, int);
	if (prefix)
		ft_fill_space(c_pre, (prefix - nbr_length(nbr)), count);
	ft_putnbr(nbr, count);
}

void	to_unsigned_decimal(va_list list, int *count, int prefix, char c_pre)
{
	unsigned int nbr;

	nbr = va_arg(list, unsigned int);
	if (prefix)
		ft_fill_space(c_pre, (prefix - nbr_length(nbr)), count);
	ft_putnbr((int)nbr, count);
}

void	to_hexa(va_list list, int *count, int is_min, int prefix, char c_pre)
{
	int nbr;

	nbr = va_arg(list, int);
	if (prefix)
		ft_fill_space(c_pre, (prefix - nbr_length_hexa(nbr)), count);
	ft_putstr(ft_itoh2(nbr, is_min), count);
}

void	to_character(va_list list, int *count, int prefix, char c_pre)
{
	int nbr;

	nbr = va_arg(list, int);
	if (prefix)
		ft_fill_space(c_pre, (prefix - 1), count);
	ft_putchar(nbr, count);
}

void	to_pointer_address(va_list list, int *count, int prefix, char c_pre)
{
	void *input;

	input = va_arg(list, void *);
	if (prefix)
		ft_fill_space(c_pre, (prefix - nbr_length_hexa((unsigned long long int)input)), count);
	ft_putstr(ft_itoh((unsigned long long int)input), count);
}
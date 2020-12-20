/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_conversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:36:40 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/17 17:22:31 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	to_string(va_list list, int *count, t_struct flags)
{
	char *str;

	str = va_arg(list, char *);
	if (flags.has_multiple)
	{
		flags.spaces_number = flags.has_multiple;
		if (flags.has_zero && !flags.has_negative)
			ft_fill_space('0', (flags.spaces_number - ft_strlen(str)), count);
		else if (!flags.has_negative)
			ft_fill_space(' ', (flags.spaces_number - ft_strlen(str)), count);
	}
	
	if (flags.spaces_number && !flags.has_negative && !flags.has_multiple)
	{
		if (flags.has_zero)
			ft_fill_space('0', (flags.spaces_number - ft_strlen(str)), count);
		else
			ft_fill_space(' ', (flags.spaces_number - ft_strlen(str)), count);
	}
	if (str)
		ft_putstr(str, count);
	if (flags.has_negative)
		ft_fill_space(' ', (flags.spaces_number - ft_strlen(str)), count);
}

















void	to_decimal(va_list list, int *count, t_struct flags)
{
	int nbr;
	
	nbr = va_arg(list, int);
	if (flags.has_point && !flags.has_negative)
	{
		if (flags.has_multiple && flags.point_value > flags.has_multiple)
		{
			if (nbr < 0)
				flags.point_value -= 1;
			ft_fill_space(' ', (flags.point_value - flags.has_multiple), count);
		}
		else if (!flags.has_multiple)
		{		
			if (flags.spaces_number >= nbr_length(nbr))
			{
				if ((flags.point_value - flags.spaces_number) > 0)
					ft_fill_space(' ', (flags.point_value - flags.spaces_number), count);
			}
			else
				if ((flags.point_value - nbr_length(nbr)) > 0)
					ft_fill_space(' ', (flags.point_value - nbr_length(nbr)), count);
		}
	}

	if (flags.has_multiple)
	{
		if (nbr < 0)
		{
			if (!flags.has_point)
				flags.has_multiple -= 1;
			ft_putchar('-', count);
		}
		if ((flags.has_zero && !flags.has_negative) || flags.point_value)
		{
			ft_fill_space('0', (flags.has_multiple - nbr_length(nbr)), count);
		}
		else if (!flags.has_negative)
			ft_fill_space(' ', (flags.has_multiple - nbr_length(nbr)), count);
	}
	else if ( (flags.spaces_number && !flags.has_negative && !flags.has_multiple) || (flags.spaces_number && flags.has_negative && flags.point_value) )
	{
		if (nbr < 0)
			ft_putchar('-', count);
		if (flags.has_zero || flags.point_value)
			ft_fill_space('0', (flags.spaces_number - nbr_length(nbr)), count);
		else
			ft_fill_space(' ', (flags.spaces_number - nbr_length(nbr)), count);
	}
	else if (nbr < 0)
		ft_putchar('-', count);
	if (nbr == 0 && flags.point_value && (!flags.spaces_number && !flags.has_multiple))
		ft_putchar(' ', count);
	else
		ft_putnbr(nbr, count);
	if (flags.spaces_number && flags.has_negative && !flags.has_point)
	{
		ft_fill_space(' ', (flags.spaces_number - nbr_length(nbr)), count);
	}
	else if (flags.has_multiple && flags.has_negative && !flags.has_point)
	{
		ft_fill_space(' ', (flags.has_multiple - nbr_length(nbr)), count);
	}
	else if (flags.has_negative && flags.has_point && !flags.point_value)
		ft_fill_space('0', (flags.spaces_number - nbr_length(nbr)), count);
	else if (flags.has_negative && flags.point_value && !flags.has_multiple)
	{
		if (flags.spaces_number < nbr_length(nbr))
			flags.spaces_number = nbr_length(nbr);
		if (nbr < 0)
			flags.point_value -= 1;
		if ((flags.point_value - flags.spaces_number) > 0)
			ft_fill_space(' ', (flags.point_value - flags.spaces_number), count);
	}
	else if (flags.has_negative && flags.point_value && flags.has_multiple)
	{
		if (flags.has_multiple < nbr_length(nbr))
			flags.has_multiple = nbr_length(nbr);
		
		if ((flags.point_value - flags.has_multiple) > 0)
			ft_fill_space(' ', (flags.point_value - flags.has_multiple), count);
	}
}



























void	to_unsigned_decimal(va_list list, int *count, t_struct flags)
{
	unsigned int	nbr;

	nbr = va_arg(list, unsigned int);
	if (flags.has_multiple)
	{
		flags.spaces_number = flags.has_multiple;
		if (flags.has_zero && !flags.has_negative)
			ft_fill_space('0', (flags.spaces_number - nbr_length(nbr)), count);
		else if (!flags.has_negative)
			ft_fill_space(' ', (flags.spaces_number - nbr_length(nbr)), count);
	}
	
	if (flags.spaces_number && !flags.has_negative && !flags.has_multiple)
	{
		if (flags.has_zero)
			ft_fill_space('0', (flags.spaces_number - nbr_length(nbr)), count);
		else
			ft_fill_space(' ', (flags.spaces_number - nbr_length(nbr)), count);
	}
	ft_putnbr((int)nbr, count);
	if (flags.has_negative)
		ft_fill_space(' ', (flags.spaces_number - nbr_length(nbr)), count);
}

void	to_hexa(va_list list, int *count, int is_min, t_struct flags)
{
	int	nbr;

	nbr = va_arg(list, int);
	if (flags.has_multiple)
	{
		flags.spaces_number = flags.has_multiple;
		if (flags.has_zero && !flags.has_negative)
			ft_fill_space('0', (flags.spaces_number - nbr_length_hexa(nbr)), count);
		else if (!flags.has_negative)
			ft_fill_space(' ', (flags.spaces_number - nbr_length_hexa(nbr)), count);
	}
	
	if (flags.spaces_number && !flags.has_negative && !flags.has_multiple)
	{
		if (flags.has_zero)
			ft_fill_space('0', (flags.spaces_number - nbr_length_hexa(nbr)), count);
		else
			ft_fill_space(' ', (flags.spaces_number - nbr_length_hexa(nbr)), count);
	}
	ft_putstr(ft_itoh2(nbr, is_min), count);
	if (flags.has_negative)
		ft_fill_space(' ', (flags.spaces_number - nbr_length_hexa(nbr)), count);
}

void	to_character(va_list list, int *count, t_struct flags)
{
	int	nbr;

	nbr = va_arg(list, int);
	if (flags.has_multiple)
	{
		flags.spaces_number = flags.has_multiple;
		if (flags.has_zero && !flags.has_negative)
			ft_fill_space('0', (flags.spaces_number - 1), count);
		else if (!flags.has_negative)
			ft_fill_space(' ', (flags.spaces_number - 1), count);
	}
	
	if (flags.spaces_number && !flags.has_negative && !flags.has_multiple)
	{
		if (flags.has_zero)
			ft_fill_space('0', (flags.spaces_number - 1), count);
		else
			ft_fill_space(' ', (flags.spaces_number - 1), count);
	}
	ft_putchar(nbr, count);
	if (flags.has_negative)
		ft_fill_space(' ', (flags.spaces_number - 1), count);
}

void	to_pointer_address(va_list list, int *count, t_struct flags)
{

	void *input;

	input = va_arg(list, void *);
	if (flags.has_multiple)
	{
		flags.spaces_number = flags.has_multiple;
		if (flags.has_zero && !flags.has_negative)
			ft_fill_space('0', (flags.spaces_number -  nbr_length_hexa((unsigned long)input)), count);
		else if (!flags.has_negative)
			ft_fill_space(' ', (flags.spaces_number -  nbr_length_hexa((unsigned long)input)), count);
	}
	
	if (flags.spaces_number && !flags.has_negative && !flags.has_multiple)
	{
		if (flags.has_zero)
			ft_fill_space('0', (flags.spaces_number -  nbr_length_hexa((unsigned long)input)), count);
		else
			ft_fill_space(' ', (flags.spaces_number -  nbr_length_hexa((unsigned long)input)), count);
	}
	ft_putstr(ft_itoh((unsigned long)input), count);
	if (flags.has_negative)
		ft_fill_space(' ', (flags.spaces_number -  nbr_length_hexa((unsigned long)input)), count);
}
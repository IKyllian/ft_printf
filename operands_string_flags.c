/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operands_string_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:08:17 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/22 12:26:45 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	operands_string_dot(t_struct flags, int *count, char *str)
{
	
	if (flags.dot_value && !flags.has_negative)
	{
		if (flags.has_zero && !flags.has_negative)
		{
			if (flags.spaces_number < ft_strlen(str) && !flags.spaces_is_neg)
				ft_fill_space('0', (flags.dot_value - flags.spaces_number), count);
			else
				ft_fill_space('0', (flags.dot_value - ft_strlen(str)), count);
		}
		else if (!flags.has_negative)
		{
			if (flags.spaces_number < ft_strlen(str) && !flags.spaces_is_neg)
				ft_fill_space(' ', (flags.dot_value - flags.spaces_number), count);
			else
				ft_fill_space(' ', (flags.dot_value - ft_strlen(str)), count);
		}
	}
}

void	operands_spaces_string_prefix(t_struct flags, int *count, char *str)
{
	
	if (flags.spaces_number && !flags.has_negative && !flags.has_dot)
	{
			if (flags.has_zero)
				ft_fill_space('0', (flags.spaces_number - ft_strlen(str)), count);
			else
				ft_fill_space(' ', (flags.spaces_number - ft_strlen(str)), count);
	}
}

void	operands_spaces_string_suffix(t_struct flags, int *count, char *str)
{
	if (flags.has_negative && !flags.has_dot)
		ft_fill_space(' ', (flags.spaces_number - ft_strlen(str)), count);
	else if (flags.has_dot && flags.spaces_is_neg && !flags.has_multiple)
		ft_fill_space(' ', (flags.spaces_number), count);
	else if (flags.has_negative && flags.dot_value)
	{
		if (flags.spaces_is_neg)
			ft_fill_space(' ', (flags.dot_value - ft_strlen(str)), count);
		else if (flags.spaces_number >= ft_strlen(str))
			ft_fill_space(' ', (flags.dot_value - ft_strlen(str)), count);
		else
			ft_fill_space(' ', (flags.dot_value - flags.spaces_number), count);
	}
}

void	print_string(t_struct flags, int *count, char *str)
{
	int i;
	int size;

	i = 0;
	size = 0;
	if (flags.has_dot)
	{
		if (flags.spaces_number)
		{
			if (flags.spaces_is_neg && flags.has_multiple)
				size = ft_strlen(str);
			else if (flags.spaces_is_neg && !flags.has_multiple)
				size = 0;
			else
				size = flags.spaces_number;
		}
		if (size > ft_strlen(str))
			size = ft_strlen(str);
		while (str && size--)
			ft_putchar(str[i++], count);
	}
	else
		ft_putstr(str, count);
}
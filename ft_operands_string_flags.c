/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operands_string_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:08:17 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/28 12:02:50 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	operands_string_dot(t_flags flags, int *count, char *str)
{
	if (flags.dot_val && !flags.has_neg)
	{
		if (flags.has_zero && !flags.has_neg)
		{
			if (flags.len_field < ft_strlen(str) && !flags.len_is_neg)
				fill_space('0', (flags.dot_val - flags.len_field), count);
			else
				fill_space('0', (flags.dot_val - ft_strlen(str)), count);
		}
		else if (!flags.has_neg)
		{
			if (flags.len_field < ft_strlen(str) && !flags.len_is_neg)
				fill_space(' ', (flags.dot_val - flags.len_field), count);
			else
				fill_space(' ', (flags.dot_val - ft_strlen(str)), count);
		}
	}
}

void	ope_space_string(t_flags flags, int *count, char *str)
{
	if (flags.len_field && !flags.has_neg && !flags.has_dot)
	{
		if (flags.has_zero)
			fill_space('0', (flags.len_field - ft_strlen(str)), count);
		else
			fill_space(' ', (flags.len_field - ft_strlen(str)), count);
	}
}

void	ope_space_string_suff(t_flags flags, int *count, char *str)
{
	if (flags.has_neg && !flags.has_dot)
		fill_space(' ', (flags.len_field - ft_strlen(str)), count);
	else if (flags.has_dot && flags.len_is_neg && !flags.has_star)
		fill_space(' ', (flags.len_field), count);
	else if (flags.has_neg && flags.dot_val)
	{
		if (flags.len_is_neg)
			fill_space(' ', (flags.dot_val - ft_strlen(str)), count);
		else if (flags.len_field >= ft_strlen(str))
			fill_space(' ', (flags.dot_val - ft_strlen(str)), count);
		else
			fill_space(' ', (flags.dot_val - flags.len_field), count);
	}
}

void	print_string(t_flags flags, int *count, char *str)
{
	int i;
	int size;

	i = 0;
	size = 0;
	if (flags.has_dot)
	{
		if (flags.len_field)
		{
			if (flags.len_is_neg && flags.has_star)
				size = ft_strlen(str);
			else if (flags.len_is_neg && !flags.has_star)
				size = 0;
			else
				size = flags.len_field;
		}
		if (size > ft_strlen(str))
			size = ft_strlen(str);
		while (str && size--)
			ft_putchar(str[i++], count);
	}
	else
		ft_putstr(str, count);
}

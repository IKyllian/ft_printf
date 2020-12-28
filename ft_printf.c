/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 09:56:31 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/28 12:38:42 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_struct_spaces(char **str, t_flags *flags)
{
	char	*nb_spaces;
	int		i;

	i = 0;
	while ((*str)[i] && ((*str)[i] >= 48 && (*str)[i] <= 57))
		i++;
	if (*(*str - 1) == '-' && *(*str - 2) == '.')
		i++;
	if (!(nb_spaces = malloc(sizeof(char) * (i + 1))))
		return ;
	i = 0;
	if (*(*str - 1) == '-' && *(*str - 2) == '.')
		nb_spaces[i++] = '-';
	while (*(*str) && (*(*str) >= 48 && *(*str) <= 57))
		nb_spaces[i++] = *(*str)++;
	nb_spaces[i] = 0;
	if (*(*str) == '.')
	{
		flags->has_dot = 1;
		flags->dot_val = ft_atoi(nb_spaces);
		(*str)++;
	}
	else
		flags->len_field = ft_atoi(nb_spaces);
	free(nb_spaces);
}

void	fill_struct_star(char **str, t_flags *flags, va_list list)
{
	int nb;

	nb = va_arg(list, int);
	if (*(*str + 1) == '.')
	{
		flags->has_dot = 1;
		flags->dot_val = nb;
		(*str)++;
	}
	else
	{
		flags->len_field = nb;
		flags->has_star = 1;
	}
}

void	check_prefix(char **str, t_flags *flags, va_list list)
{
	while (*(*str) && !is_conversions(*(*str)))
	{
		if (*(*str) == '0' && !flags->has_neg && !flags->has_dot)
			flags->has_zero = 1;
		if (*(*str) == '-')
		{
			if (flags->has_zero)
				flags->has_zero = 0;
			flags->has_neg = 1;
		}
		if (*(*str) == '.')
			flags->has_dot = 1;
		if (*(*str) == '*')
			fill_struct_star(str, flags, list);
		if (*(*str) >= 48 && *(*str) <= 57)
			fill_struct_spaces(str, flags);
		else
			(*str)++;
	}
}

void	ft_display(char **str, va_list list, int *count)
{
	t_flags flags;

	struct_initialize(&flags);
	if (!is_conversions(*(*str)))
		check_prefix(str, &flags, list);
	if (*(*str) == 's')
		to_string(list, count, flags);
	else if (*(*str) == 'd' || *(*str) == 'i')
		to_decimal(list, count, &flags);
	else if (*(*str) == 'u')
		to_unsigned_decimal(list, count, &flags);
	else if (*(*str) == 'x')
		to_hexa(list, count, 1, &flags);
	else if (*(*str) == 'X')
		to_hexa(list, count, 0, &flags);
	else if (*(*str) == 'c')
		to_character(list, count, &flags);
	else if (*(*str) == '%')
		to_percent(count, &flags);
	else if (*(*str) == 'p')
		to_pointer_address(list, count, &flags);
}

int		ft_printf(const char *format, ...)
{
	va_list list;
	int		count;
	char	*str;

	str = (char *)format;
	va_start(list, format);
	count = 0;
	while (*str)
	{
		if (*str != '%')
			ft_putchar(*str, &count);
		else
		{
			++str;
			ft_display(&str, list, &count);
		}
		str++;
	}
	va_end(list);
	return (count);
}

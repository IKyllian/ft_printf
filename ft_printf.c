/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 09:56:31 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/22 17:53:05 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	struct_initialize(t_struct *flags)
{
	flags->has_negative = 0;
	flags->spaces_number = 0;
	flags->has_dot = 0;
	flags->dot_value = 0;
	flags->has_zero = 0;
	flags->has_multiple = 0;
}

int		is_conversions(char c)
{
	if (c == 's' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' ||
		c == 'c' || c == '%' || c == 'p')
		return (1);
	else
		return (0);
}

t_struct	check_prefix(char **str, va_list list)
{
	t_struct flags;
	int i;
	int nb;
	char *nb_spaces;

	i = 0;
	nb = 0;
	struct_initialize(&flags);
	while (*(*str) && !is_conversions(*(*str)))
	{
		if (*(*str) == '0' && !flags.has_negative && !flags.has_dot)
			flags.has_zero = 1;
		if (*(*str) == '-')
		{
			if (flags.has_zero)
				flags.has_zero = 0;
			flags.has_negative = 1;
		}
		if (*(*str) == '.')
			flags.has_dot = 1;
		if (*(*str) == '*')
		{
			nb = va_arg(list, int);
			if (*(*str + 1) == '.')
			{
				flags.has_dot = 1;
				flags.dot_value = nb;
				(*str)++;
			}
			else
				flags.has_multiple = nb;
		}
		if (*(*str) >= 48 && *(*str) <= 57)
		{
			while ((*str)[i] && ((*str)[i] >= 48 && (*str)[i] <= 57))
				i++;
			nb_spaces = malloc(sizeof(char) * (i + 1));
			//if (!(nb_spaces = malloc(sizeof(char) * (i + 1))))
			//	return (NULL);
			i = 0;
			while (*(*str) && (*(*str) >= 48 && *(*str) <= 57))
			{
				nb_spaces[i++] = *(*str);
				(*str)++;
			}
			nb_spaces[i] = 0;
			nb = ft_atoi(nb_spaces);
			free(nb_spaces);
			if (*(*str) == '.')
			{
				flags.has_dot = 1;
				flags.dot_value = nb;
				(*str)++;
			}
			else
				flags.spaces_number = nb;
		}
		else
			(*str)++;
	}
	return (flags);
}

void	ft_display(char **str, va_list list, int *count)
{
	t_struct flags;

	struct_initialize(&flags);
	if (!is_conversions(*(*str)))
		flags = check_prefix(str, list);
	if (*(*str) == 's')
		to_string(list, count, flags);
	else if (*(*str) == 'd' || *(*str) == 'i')
		to_decimal(list, count, flags);
	else if (*(*str) == 'u')
		to_unsigned_decimal(list, count, flags);
	else if (*(*str) == 'x')
		to_hexa(list, count, 1, flags);
	else if (*(*str) == 'X')
		to_hexa(list, count, 0, flags);
	else if (*(*str) == 'c')
		to_character(list, count, flags);
	else if (*(*str) == '%')
		ft_putchar('%', count);
	else if (*(*str) == 'p')
		to_pointer_address(list, count, flags);
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


//  int		main()
//  {
// // 	int nb = 42;
// // 	char *str = "TEST";
// // 	int c = 0;
// // 	unsigned int u_nb = 10;
//  	int res;
//  	int res2;
// // 	//float fnb = 52.48797979796;

// // 	//res = ft_printf("Mine Printf test  - %010s - %-6i - %-05c - %0-----010p - %10u - %0000-0009x\n", str, nb, c, &c, u_nb, nb);
// // 	//res2 = printf("Real Printf test  - %010s - %-6i - %-05c - %0----010p - %10u - %0000-00009x\n", str, nb, c, &c, u_nb, nb);

// // 	//printf("Test flag : %-10d\n", nb);
//  	 //res = ft_printf("Mine %-2.2d\n", 0);
//  	 //res2 = printf  ("Real %-2.2d\n", 0);

// 	// res = ft_printf("Mine %*.s %.1s\n", 10, "123", "4567");
// 	// res2 = printf  ("Real %*.s %.1s\n", 10, "123", "4567");

// 	// res = ft_printf("Mine %*.0s %.2s\n", 10, "123", "4567");
// 	// res2 = printf  ("Real %*.0s %.2s\n", 10, "123", "4567");

// 	// res = ft_printf("Mine %*.3s %.3s\n", 10, "123", "4567");
// 	// res2 = printf  ("Real %*.3s %.3s\n", 10, "123", "4567");

// 	// res = ft_printf("Mine %*.4s %.4s\n", 10, "123", "4567");
// 	// res2 = printf  ("Real %*.4s %.4s\n", 10, "123", "4567");

// 	// res = ft_printf("Mine %10i %010i\n", 1, -1);
// 	 //res2 = printf  ("Real %10i %010i\n", 1, -1);

// 	//res = ft_printf("Mine %0*d\n", -4, -12);
// 	//res2 = printf  ("Real %0*d\n", -4, -12);

// 	res = ft_printf("Mine %0*.*i\n", 4, -2, -12);
// 	res2 = printf  ("Real %0*.*i\n", 4, -2, -12);

// //	res = ft_printf("Mine %.*i\n", -4, 8);
// //	res2 = printf  ("Real %.*i\n", -4, 8);

// 	//res = ft_printf("Mine *%-*.*i* *%*.*i*\n",4, 5, 10, 10, 21, -10);
// 	//res2 = printf  ("Real *%-*.*i* *%*.*i*\n", 4, 5, 10, 10, 21, -10);

// 	// printf("Res = %i\n", res);
// 	// printf("Res2 = %i\n", res2);
// 	// res = ft_printf("Mine 0*%0-*.*d*0 0*%0*.*d*0\n", 2, 6, 102, 21, 10, -101);
// 	// res2 = printf  ("Real 0*%0-*.*d*0 0*%0*.*d*0\n", 2, 6, 102, 21, 10, -101);
//  	//res2 = printf(" *%-*.*i* *%*.*i* ", 6, 5, 10, 10, 21, -10);
//  	printf("Res = %i\n", res);
// 	printf("Res2 = %i", res2);
//  }
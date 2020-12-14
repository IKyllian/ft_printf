/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 09:56:31 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/14 18:26:40 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_prefix(char **str, char *c_pre)
{
	int		i;
	char	*spaces;

	i = 0;
	if ((*str)[i] == 48)
		*c_pre = '0';
	else
		*c_pre = ' ';
	while ((*str)[i] && ((*str)[i] >= 48 && (*str)[i] <= 57))
		i++;
	if (!(spaces = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (*(*str) && (*(*str) >= 48 && *(*str) <= 57))
	{
		spaces[i++] = *(*str);
		(*str)++;
	}
	spaces[i] = 0;
	return (spaces);
}

void	ft_display(char **str, va_list list, int *count)
{
	int		prefix;
	char	character_pre;

	prefix = ft_atoi(check_prefix(str, &character_pre));
	if (*(*str) == 's')
		to_string(list, count, prefix, character_pre);
	else if (*(*str) == 'd' || *(*str) == 'i')
		to_decimal(list, count, prefix, character_pre);
	else if (*(*str) == 'u')
		to_unsigned_decimal(list, count, prefix, character_pre);
	else if (*(*str) == 'x')
		to_hexa(list, count, 1, prefix, character_pre);
	else if (*(*str) == 'X')
		to_hexa(list, count, 0, prefix, character_pre);
	else if (*(*str) == 'c')
		to_character(list, count, prefix, character_pre);
	else if (*(*str) == '%')
		ft_putchar('%', count);
	else if (*(*str) == 'p')
		to_pointer_address(list, count, prefix, character_pre);
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

int		main()
{
	int nb = 42;
	char *str = "TEST";
	int c = 0;
	unsigned int u_nb = 10;
	int res;
	int res2;
	float fnb = 52.48797979796;

	res = ft_printf("Mine Printf test  - %020s - %015i - %05c - %010p - %06u - %09X\n", str, nb, c, &c, u_nb, nb);
	res2 = printf("Real Printf test  - %020s - %015i - %05c - %010p - %06u - %09X\n", str, nb, c, &c, u_nb, nb);

	//printf("Test flag : %-10d\n", nb);

	//res = ft_printf("Mine Printf %x\n", nb);
	//res2 = printf("Real Printf %x\n", nb);
	printf("Res = %i\n", res);
	printf("Res2 = %i", res2);
}

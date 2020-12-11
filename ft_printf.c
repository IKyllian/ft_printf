/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 09:56:31 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/11 17:20:49 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display(char c, va_list list)
{
	char		*string;
	int			nbr;
	void		*var;
	unsigned	u_nbr;

	if (c == 's')
	{
		string = va_arg(list, char *);
		if (string)
			while (*string)
				ft_putchar(*string++);
	}
	else if (c == 'd' || c == 'i')
	{
		nbr = va_arg(list, int);
		ft_putnbr(nbr);
	}
	else if (c == 'u')
	{
		u_nbr = va_arg(list, unsigned int);
		ft_putnbr((int)u_nbr);
	}
	else if (c == 'x')
	{
		nbr = va_arg(list, int);
		ft_putstr(ft_itoh2(nbr));
	}
	else if (c == 'c')
	{
		nbr = va_arg(list, int);
		ft_putchar(nbr);
	}
	else if (c == '%')
		ft_putchar('%');
	else if (c == 'p')
	{
		var = va_arg(list, void *);
		ft_putstr(ft_itoh((unsigned long long int)var));
	}
}

int		ft_printf(const char *str, ...)
{
	va_list list;
	int		i;
	int 	count;

	va_start(list, str);
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i]);
		else
			ft_display(str[++i], list);
		i++;
	}
	va_end(list);
	return (i);
}

int		main()
{
	int nb = 42;
	char *str = "TES";
	int c = 60;
	unsigned int u_nb = 10;
	int res;
	int res2;

	res = ft_printf("Mine Printf test  - %s - %i - %c - %p - %u - %x \n", str, nb, c, &c, u_nb, nb);
	res2 = printf("Real Printf test  - %s - %i - %c - %p - %u - %x\n", str, nb, c, &c, u_nb, nb);
	printf("Res = %i\n", res);
	printf("Res2 = %i", res2);
}
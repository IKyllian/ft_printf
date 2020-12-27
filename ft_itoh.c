/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 13:07:45 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/22 14:56:44 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nbr_length(int nbr)
{
	int			length;
	long long	l_nbr;

	l_nbr = nbr;
	length = 0;
	if (l_nbr < 0)
		l_nbr *= -1;
	while (l_nbr >= 10)
	{
		length++;
		l_nbr /= 10;
	}
	return (++length);
}

int		u_nbr_length(unsigned long nbr, unsigned int size_base)
{
	int			length;

	length = 0;
	while (nbr >= size_base)
	{
		length++;
		nbr /= size_base;
	}
	return (++length);
}

void	ft_print_itoh(unsigned long nbr, int is_min, int is_address, int *count)
{
	char	*str;
	int		i;
	char	*base;

	i = u_nbr_length(nbr, 16);
	if (is_address)
		i += 2;
	if (is_min)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (!(str = malloc(sizeof(char) * (u_nbr_length(nbr, 16) + 1))))
		return ;
	str[i--] = 0;
	if (nbr == 0)
		str[i--] = '0';
	while (nbr)
	{
		str[i--] = base[nbr % 16];
		nbr /= 16;
	}
	if (is_address)
	{
		str[i--] = 'x';
		str[i] = '0';
	}
	ft_putstr(str, count);
	free(str);
}
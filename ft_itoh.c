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

int		u_nbr_length(unsigned long nbr)
{
	int			length;

	length = 0;
	while (nbr >= 10)
	{
		length++;
		nbr /= 10;
	}
	return (++length);
}

int		nbr_length_hexa(unsigned long nbr)
{
	int length;

	length = 0;
	while (nbr >= 16)
	{
		length++;
		nbr /= 16;
	}
	return (++length);
}

char	*ft_itoh(unsigned long nbr)
{
	char	*str;
	int		i;
	char	*base;

	i = nbr_length_hexa(nbr) + 2;
	base = "0123456789abcdef";
	if (!(str = malloc(sizeof(char) * (nbr_length_hexa(nbr) + 3))))
		return (NULL);
	str[i--] = 0;
	if (nbr == 0)
		str[i--] = '0';
	while (nbr)
	{
		str[i--] = base[nbr % 16];
		nbr /= 16;
	}
	str[i--] = 'x';
	str[i] = '0';
	return (str);
}

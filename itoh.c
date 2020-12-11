/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 13:07:45 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/11 15:28:47 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nbr_length(unsigned long long int nbr)
{
	int length;

	length = 0;
	while (nbr)
	{
		length++;
		nbr /= 16;
	}
	return (length);
}

char	*ft_itoh(unsigned long long int nbr)
{
	char *str;
	int i;
	char *base;
	int final_int[100];
	int x;

	x = 0;
	i = 0;
	base = "0123456789abcdef";
	if (!(str = malloc(sizeof(char) * (nbr_length(nbr) + 3)))) // +3 pour le 0x de l'adresse et le \0
		return (NULL);
	str[x++] = '0';
	str[x++] = 'x';
	while (nbr)
	{
		final_int[i++] = nbr % 16;
		nbr /= 16;
	}
	while (--i >= 0)
		str[x++] = base[final_int[i]];
	str[x] = 0;
	return (str);
}
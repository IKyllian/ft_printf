/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 15:27:19 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/22 13:36:03 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoh2(unsigned long nbr, int is_min)
{
	char	*str;
	char	*base;
	int		i;

	i = nbr_length_hexa(nbr);
	if (is_min)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (!(str = malloc(sizeof(char) * (nbr_length_hexa(nbr) + 1))))
		return (NULL);
	str[i--] = 0;
	if (nbr == 0)
		str[i] = '0';
	while (nbr)
	{
		str[i--] = base[nbr % 16];
		nbr /= 16;
	}
	return (str);
}

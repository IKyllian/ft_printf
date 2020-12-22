/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 15:27:19 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/22 12:51:41 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoh2(unsigned long long nbr, int is_min)
{
	char	*str;
	char	*base;
	int		i;

	printf("nbr = %lli\n", nbr);
	i = nbr_length(nbr);
	if (is_min)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (!(str = malloc(sizeof(char) * (nbr_length(nbr) + 1))))
		return (NULL);
	if (nbr < 0)
		nbr *= -1;
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

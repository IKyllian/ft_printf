/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 15:27:19 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/11 16:20:25 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoh2(int nbr)
{
	char	*str;
	char	*base;
	int		i;

	i = nbr_length(nbr);
	base = "0123456789abcdef";
	if (!(str = malloc(sizeof(char) * (nbr_length(nbr) + 1))))
		return (NULL);
	str[i--] = 0;
	while (nbr)
	{
		str[i--] = base[nbr % 16];
		nbr /= 16;
	}
	return (str);
}

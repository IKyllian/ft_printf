/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:15:16 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/14 12:58:12 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	i = -1;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	len = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++len])
		str[i + len] = s2[len];
	str[i + len] = '\0';
	printf("2 str = %s\n", str);
	return (str);
}
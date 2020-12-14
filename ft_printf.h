/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:40:28 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/14 18:25:17 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	ft_putchar(char c, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putstr(char *str, int *count);
char	*ft_itoh(unsigned long long int nbr);
char	*ft_itoh2(int nbr, int is_min);
int		nbr_length(int nbr);
char	*ft_strjoin(char *s1, char *s2);
int		ft_atoi(char *nptr);
int		ft_strlen(const char *s);
void	to_decimal(va_list list, int *count, int prefix, char c_pre);
void	to_unsigned_decimal(va_list list, int *count, int prefix, char c_pre);
void	to_hexa(va_list list, int *count, int is_min, int prefix, char c_pre);
void	to_character(va_list list, int *count, int prefix, char c_pre);
void	to_pointer_address(va_list list, int *count, int prefix, char c_pre);
void	to_string(va_list list, int *count, int prefix, char c_pre);
void	ft_fill_space(char c, int size, int *count);
int		nbr_length_hexa(unsigned long long int nbr);

#endif
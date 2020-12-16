/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:40:28 by kdelport          #+#    #+#             */
/*   Updated: 2020/12/15 15:23:09 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct	s_struct
{
	int 		has_negative;
	int 		has_zero;
	int 		spaces_number;
	int 		has_point;
	int 		has_multiple;
}				t_struct;

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putstr(char *str, int *count);
char	*ft_itoh(unsigned long nbr);
char	*ft_itoh2(int nbr, int is_min);
int		nbr_length(int nbr);
char	*ft_strjoin(char *s1, char *s2);
int		ft_atoi(char *nptr);
int		ft_strlen(const char *s);
void	to_decimal(va_list list, int *count, t_struct flags);
void	to_unsigned_decimal(va_list list, int *count, t_struct flags);
void	to_hexa(va_list list, int *count, int is_min, t_struct flags);
void	to_character(va_list list, int *count, t_struct flags);
void	to_pointer_address(va_list list, int *count, t_struct flags);
void	to_string(va_list list, int *count, t_struct flags);
void	ft_fill_space(char c, int size, int *count);
int		nbr_length_hexa(unsigned long nbr);

#endif
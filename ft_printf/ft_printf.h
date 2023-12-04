/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:47:13 by mhiguera          #+#    #+#             */
/*   Updated: 2023/07/04 17:21:15 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printchar(char c);
int		ft_printpercent(void);
int		ft_format(va_list objects, char format);
int		ft_printf(char const *str, ...);
int		ft_printstr(char *str);
int		ft_printpointer(unsigned long ptr);
int		ft_printnbr(int num);
int		ft_printunsigned(unsigned int u);
int		ft_printhexalow(unsigned int num);
int		ft_printhexacap(unsigned int num);
long	ft_pointertohexa(unsigned long num);
#endif

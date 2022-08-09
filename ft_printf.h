/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: as <as@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:01:08 by a         #+#    #+#             */
/*   Updated: 2022/01/24 15:34:29 by a         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printchar(char c);
int	ft_printstr(char *s);
int	ft_printnmb(int n);
int	ft_print_unsg_nmb(unsigned int n);
int	ft_print_pointer(unsigned long long n);
int	ft_printf(const char *s, ...);
int	ft_print_uhex(unsigned int n);
int	ft_print_dhex(unsigned int n);
int	ft_type(const char c, va_list *ap);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:12:33 by a          #+#    #+#             */
/*   Updated: 2022/03/14 16:24:02 by a         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uhex(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i = i + ft_print_uhex(n / 16);
		i = i + ft_print_uhex(n % 16);
	}
	else
	{
		if (n < 10)
			i = i + ft_printchar(n + '0');
		else
			i = i + ft_printchar('A' + n - 10);
	}
	return (i);
}

int	ft_print_dhex(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i = i + ft_print_dhex(n / 16);
		i = i + ft_print_dhex(n % 16);
	}
	else
	{
		if (n < 10)
			i = i + ft_printchar(n + '0');
		else
			i = i + ft_printchar('a' + n - 10);
	}
	return (i);
}

int	ft_type(const char c, va_list *ap)
{
	if (c == 'c')
		return (ft_printchar(va_arg(*ap, int)));
	if (c == 's')
		return (ft_printstr(va_arg(*ap, char *)));
	if (c == 'p')
	{
		ft_printstr("0x");
		return (ft_print_pointer(va_arg(*ap, unsigned long long)) + 2);
	}
	if (c == 'd' || c == 'i')
		return (ft_printnmb(va_arg(*ap, int)));
	if (c == 'u')
		return (ft_print_unsg_nmb(va_arg(*ap, unsigned int)));
	if (c == 'x')
		return (ft_print_dhex(va_arg(*ap, unsigned int)));
	if (c == 'X')
		return (ft_print_uhex(va_arg(*ap, unsigned int)));
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		say;

	say = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s != '%')
		{
			ft_printchar(*s++);
			say++;
			continue ;
		}
		if (*s++)
			say = say + ft_type(*s, &ap);
		s++;
	}
	va_end(ap);
	return (say);
}

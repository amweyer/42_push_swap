/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:45:54 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/07 10:37:10 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p(unsigned long ptr)
{
	int	l;

	l = 0;
	if (ptr == 0)
		l += ft_putstr("(nil)");
	else
	{
		l += ft_putstr("0x");
		l += ft_putnbr_bu(ptr, "0123456789abcdef");
	}
	return (l);
}

int	ft_dispatch(char c, va_list *args)
{
	int	l;

	l = 0;
	if (c == '%')
		l += ft_putchar('%');
	else if (c == 'c')
		l += ft_putchar((char)va_arg(*args, int));
	else if (c == 's')
		l += ft_putstr(va_arg(*args, char *));
	else if (c == 'u')
		l += ft_putnbr_bu(va_arg(*args, unsigned int), "0123456789");
	else if (c == 'x')
		l += ft_putnbr_bu((unsigned int)va_arg(*args, int), "0123456789abcdef");
	else if (c == 'X')
		l += ft_putnbr_bu((unsigned int)va_arg(*args, int), "0123456789ABCDEF");
	else if (c == 'd' || c == 'i')
		l += ft_putnbr_b(va_arg(*args, int), "0123456789");
	else if (c == 'p')
		l += ft_printf_p((unsigned long)va_arg(*args, void *));
	return (l);
}

int	ft_strchr(const char *s, int c)
{
	int		i;
	char	*s1;

	i = 0;
	s1 = (char *)s;
	while (s1[i] != '\0')
	{
		if (s1[i] == (unsigned char)c)
			return (1);
		i++;
	}
	if (s1[i] == (unsigned char)c)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:59:44 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/07 10:38:06 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_dispatch(char c, va_list *args);
int	ft_strlen(char *str);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr_b(int n, char *base);
int	ft_putnbr_bu(unsigned long nb, char *base);
int	ft_strchr(const char *s, int c);
int	ft_printf_p(unsigned long ptr);

#endif
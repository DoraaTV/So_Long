/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:34:48 by thrio             #+#    #+#             */
/*   Updated: 2023/01/14 20:48:37 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_putchar_int(char c)
{
	if (!write(1, &c, 1))
		return (0);
	return (1);
}

int	ft_putstr_int(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr_int("(null)"));
	while (s[i])
	{
		if (!write(1, &s[i], 1))
			return (i);
		i++;
	}
	return (i);
}

int	ft_checker(char c, va_list s)
{
	if (c == 'c')
		return (ft_putchar_int(va_arg(s, int)));
	else if (c == 's')
		return (ft_putstr_int(va_arg(s, char *)));
	else if (c == 'p')
		return (ft_print_p(va_arg(s, long unsigned int)));
	else if (c == 'd')
		return (ft_putnbr_int(va_arg(s, int)));
	else if (c == 'i')
		return (ft_putnbr_int(va_arg(s, int)));
	else if (c == 'u')
		return (ft_putnbr_int(va_arg(s, unsigned int)));
	else if (c == 'x')
		return (ft_printxx(va_arg(s, unsigned int), c));
	else if (c == 'X')
		return (ft_printxx(va_arg(s, unsigned int), c));
	else if (c == '%')
		return (ft_putchar_int('%'));
	else
		ft_putchar_int(c);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list		s;
	int			counter;

	counter = 0;
	va_start(s, str);
	while (*str != '\0')
	{
		if (*str != '%')
			counter += ft_putchar_int(*str);
		else
		{
			++str;
			counter += ft_checker(*str, s);
		}
		str++;
	}
	va_end(s);
	return (counter);
}

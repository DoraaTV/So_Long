/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:21:53 by thrio             #+#    #+#             */
/*   Updated: 2023/01/14 14:25:52 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_putnbr_base(long unsigned int nb, char *base)
{
	int			counter;

	counter = 0;
	if (nb >= 16)
	{
		counter += ft_putnbr_base(nb / 16, base);
	}
	counter += ft_putchar_int(base[nb % 16]);
	return (counter);
}

int	ft_print_p(long unsigned int nb)
{
	int	counter;

	counter = 0;
	if (!nb)
		return (ft_putstr_int("(nil)"));
	ft_putstr_int("0x");
	counter += 2;
	counter += ft_putnbr_base(nb, "0123456789abcdef");
	return (counter);
}

int	ft_putnbr_int(long int nbr)
{
	int		counter;

	counter = 0;
	if (nbr == -2147483647)
	{
		counter += ft_putstr_int("-2147483647");
		return (counter);
	}
	if (nbr < 0)
	{
		counter += ft_putchar_int('-');
		nbr = -nbr;
	}
	if (nbr > 9)
		counter += ft_putnbr_int(nbr / 10);
	counter += ft_putchar_int(nbr % 10 + 48);
	return (counter);
}

int	ft_printxx(long long int nb, char c)
{
	int	counter;

	counter = 0;
	if (c == 'x')
		counter += ft_putnbr_base(nb, "0123456789abcdef");
	else if (c == 'X')
		counter += ft_putnbr_base(nb, "0123456789ABCDEF");
	return (counter);
}

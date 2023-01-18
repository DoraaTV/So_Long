/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:39:11 by thrio             #+#    #+#             */
/*   Updated: 2023/01/18 20:34:26 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

char	*ft_strdup(char *src)
{
	char	*sortie;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(src);
	sortie = (char *) malloc(sizeof(char) * (size + 1));
	while (src[i])
	{
		sortie[i] = src[i];
		i++;
	}
	sortie[i] = '\0';
	return (sortie);
}

static int	sizer(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		i++;
		n = n / 10;
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	long int	nbr;
	char		*res;
	int			i;

	nbr = n;
	i = sizer(n) - 1;
	if (nbr < 0)
	{
		res = malloc(sizeof(char) * (sizer(n) + 2));
		nbr = -nbr;
		res[0] = '-';
		i++;
	}
	else
		res = malloc(sizeof(char) * (sizer(n)) + 1);
	res[i + 1] = '\0';
	while (nbr > 9)
	{
		res[i] = (char)(nbr % 10 + 48);
		nbr = nbr / 10;
		i--;
	}
	res[i] = nbr + 48;
	return (res);
}

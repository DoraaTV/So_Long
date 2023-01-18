/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columnrowcheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:03:08 by thrio             #+#    #+#             */
/*   Updated: 2023/01/18 12:21:55 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	lineerror(t_program *param)
{
	ft_printf("Invalid map, a wall is missing on a \
line, map must be closed\n");
	ft_freemap(param);
	exit(1);
}

void	columnerror(t_program *param)
{
	ft_printf("Invalid map, a wall is missing on a \
column, map must be closed\n");
	ft_freemap(param);
	exit(1);
}

void	columncheck(t_program *param)
{
	int	i;

	i = 0;
	while (i <= param->nbline)
	{
		if (param->map[i][0] != '1')
			columnerror(param);
		if (param->map[i][param->size - 2] != '1')
			columnerror(param);
		i++;
	}
}

void	linecheck(t_program *param)
{
	int	i;

	i = 0;
	while (i < param->size)
	{
		if (param->map[0][i] != '1' && i != param->size - 1)
			lineerror(param);
		if (i != param->size - 1 && param->map[5][i] != '1')
			lineerror(param);
		i++;
	}
	i = 0;
}

void	cornercheck(t_program *param)
{
	linecheck(param);
	columncheck(param);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:33:04 by thrio             #+#    #+#             */
/*   Updated: 2023/01/18 20:38:54 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	unknownchar(t_program *test)
{
	ft_printf("The map contain a non valid char\n");
	ft_freemap(test);
	exit(1);
}

int	is_validpathone(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				return (0);
		}
	}
	return (1);
}

void	ft_helper(t_program *param, int i, int fd)
{
	param->startx = 32 * (param->size - 1);
	param->starty = 32 * i;
	param->nbline = i;
	close(fd);
	map_checker(param);
	pathfinding(param);
}

void	ft_helpertwo(t_program *param, int i, int j)
{
	if (param->map[i][j] == 'P')
		param->nbrs.charnb++;
	else if (param->map[i][j] == 'E')
		param->nbrs.exitnb++;
	else if (param->map[i][j] == 'C')
		param->nbrs.ccount++;
	else if (param->map[i][j] != '0' && param->map[i][j] != '\n'
		&& param->map[i][j] != '1')
		unknownchar(param);
}

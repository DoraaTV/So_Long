/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:25:23 by thrio             #+#    #+#             */
/*   Updated: 2023/01/18 20:22:07 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**makemapcopy(t_program *param, char **dest)
{
	int	i;
	int	j;

	i = -1;
	while (param->map[++i])
	{
		j = -1;
		dest[i] = malloc(sizeof(char) * param->size + 1);
		while (param->map[i][++j])
			dest[i][j] = param->map[i][j];
		dest[i][j] = '\0';
	}
	dest[i] = 0;
	return (dest);
}

int	is_validpath(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
		}
	}
	return (1);
}

void	startpath(char **map, int i, int j)
{
	if (map[i + 1][j] != '1' && (map[i + 1][j] == '0'
		|| map[i + 1][j] == 'C' || map[i + 1][j] == 'E'))
	{
		map[i + 1][j] = '3';
		startpath(map, i + 1, j);
	}
	if ((map[i - 1][j] == '0' || map[i - 1][j] == 'C' || map[i - 1][j] == 'E'))
	{
		map[i - 1][j] = '3';
		startpath(map, i - 1, j);
	}
	if ((map[i][j + 1] == '0' || map[i][j + 1] == 'C' || map[i][j + 1] == 'E'))
	{
		map[i][j + 1] = '3';
		startpath(map, i, j + 1);
	}
	if ((map[i][j - 1] == '0' || map[i][j - 1] == 'C' || map[i][j - 1] == 'E'))
	{
		map[i][j - 1] = '3';
		startpath(map, i, j - 1);
	}
}

void	ft_close(char **map, t_program *param)
{
	int	i;

	i = 0;
	if (!is_validpath(map))
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
		ft_freemap(param);
		ft_printf("The map can't be won\n");
		exit(1);
	}
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	pathfinding(t_program *param)
{
	int		i;
	int		j;
	char	**map;

	map = malloc(sizeof(char *) * (param->nbline + 2));
	map = makemapcopy(param, map);
	i = -1;
	while (param->map[++i])
	{
		j = -1;
		while (param->map[i][++j])
		{
			if (param->map[i][j] == 'P')
			{
				firstcheck(map, i, j);
				if (!is_validpathone(map))
					ft_close(map, param);
				ft_freepath(map);
				map = makemapcopy(param, map);
				startpath(map, i, j);
			}
		}
	}
	i = 0;
	ft_close(map, param);
}

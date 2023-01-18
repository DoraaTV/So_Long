/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:56:05 by thrio             #+#    #+#             */
/*   Updated: 2023/01/18 20:37:25 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../includes/so_long.h"

void	too_much_char(t_program *test)
{
	ft_printf("There is no or too much char, only one char is required\n");
	ft_freemap(test);
	exit(1);
}

void	too_much_exit(t_program *test)
{
	ft_printf("There is no or too much exit, only one exit is required\n");
	ft_freemap(test);
	exit(1);
}

void	not_rectangle(t_program *test)
{
	ft_printf("The map is not a rectangle\n");
	ft_freemap(test);
	exit(1);
}

void	checknbrs(t_program *param)
{
	if (param->nbrs.charnb != 1)
		too_much_char(param);
	else if (param->nbrs.exitnb != 1)
		too_much_exit(param);
	else if (param->nbrs.ccount == 0)
		notenoughc(param);
	cornercheck(param);
}

void	map_checker(t_program *param)
{
	int	i;
	int	j;

	i = -1;
	while (param->map[++i])
	{
		j = -1;
		while (param->map[i][++j])
		{
			ft_helpertwo(param, i, j);
		}
		if ((i != param->nbline && j + 1 != param->size)
			|| param->nbline == param->size - 1)
			not_rectangle(param);
		else if (i == param->nbline && j - 1 != param->size)
			not_rectangle(param);
	}
	checknbrs(param);
	pathfinding(param);
}

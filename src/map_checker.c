/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:56:05 by thrio             #+#    #+#             */
/*   Updated: 2023/01/17 19:39:36 by thrio            ###   ########.fr       */
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
			if (param->map[i][j] == 'P')
				param->nbrs.charnb++;
			else if (param->map[i][j] == 'E')
				param->nbrs.exitnb++;
			else if (param->map[i][j] == 'C')
				param->nbrs.ccount++;
		}
		if ((i != param->nbline && j != param->size) || param->nbline == param->size - 2)
			not_rectangle(param);
		else if (i == param->nbline && j + 1 != param->size)
			not_rectangle(param);
	}
	checknbrs(param);
}

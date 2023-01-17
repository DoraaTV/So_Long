/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:56:05 by thrio             #+#    #+#             */
/*   Updated: 2023/01/17 19:24:10 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../includes/so_long.h"

void	whichchar(char c, int x, int y, t_program *test)
{
	if (c == '1')
		mlx_put_image_to_window(test->mlx, test->win, test->image.Rock, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(test->mlx, test->win, test->image.Char, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(test->mlx, test->win, test->image.Chest, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(test->mlx, test->win, test->image.House, x, y);
	else if (c == '0')
		mlx_put_image_to_window(test->mlx, test->win, test->image.Grass, x, y);
	else if (c != '\n')
		closererror(test);
}

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

void	map_checker(t_program *param)
{
	int	i;
	int	j;

	i = -1;
	param->nbrs.charnb = 0;
	param->nbrs.exitnb = 0;
	while (param->map[++i])
	{
		j = -1;
		while (param->map[i][++j])
		{
			if (param->map[i][j] == 'P')
				param->nbrs.charnb += 1;
			else if (param->map[i][j] == 'E')
				param->nbrs.exitnb += 1;
		}
		if ((i != param->nbline && j != param->size) || param->nbline == param->size - 2)
			not_rectangle(param);
		else if (i == param->nbline && j + 1 != param->size)
			not_rectangle(param);
	}
	if (param->nbrs.charnb != 1)
		too_much_char(param);
	else if (param->nbrs.exitnb != 1)
		too_much_exit(param);
}

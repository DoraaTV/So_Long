/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:57:43 by thrio             #+#    #+#             */
/*   Updated: 2023/01/18 19:24:27 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../includes/so_long.h"

int	put(t_program *test)
{
	int	x;
	int	y;
	int	j;
	int	n;

	y = 0;
	j = 0;
	while (test->map[j])
	{
		n = 0;
		x = 0;
		while (test->map[j][n])
		{
			whichchar(test->map[j][n], x, y, test);
			string_put(test);
			n++;
			x += 32;
		}
		y += 32;
		j++;
	}
	return (0);
}

int	closer(t_program *param)
{
	mlx_clear_window(param->mlx, param->win);
	mlx_destroy_image(param->mlx, param->image.chest);
	mlx_destroy_image(param->mlx, param->image.player);
	mlx_destroy_image(param->mlx, param->image.rock);
	mlx_destroy_image(param->mlx, param->image.grass);
	mlx_destroy_image(param->mlx, param->image.house);
	mlx_destroy_window(param->mlx, param->win);
	mlx_destroy_display(param->mlx);
	ft_freemap(param);
	free(param->mlx);
	exit(0);
	return (0);
}

int	is_finished(t_program *param)
{
	int	i;
	int	j;

	i = 0;
	while (param->map[i])
	{
		j = 0;
		while (j < param->size)
		{
			if (param->map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	key_event(int button, t_program *param)
{
	if (button == 65307)
		closer(param);
	else if (button == 119 || button == 65362)
		move_up(param);
	else if (button == 100 || button == 65363)
		move_right(param);
	else if (button == 97 || button == 65361)
		move_left(param);
	else if (button == 115 || button == 65364)
		move_down(param);
	return (0);
}

int	main(int ac, char **av)
{
	t_program	param;

	if (ac != 2)
		return (0);
	param.nbline = 0;
	param.nbrs.depcount = 0;
	param.nbrs.ccount = 0;
	param.nbrs.charnb = 0;
	param.nbrs.exitnb = 0;
	map_init(&param, av);
	param.mlx = mlx_init();
	if (!param.mlx)
		exit(1);
	set_image(&param);
	param.win = mlx_new_window(param.mlx, \
		param.startx, param.starty, "so_long");
	mlx_hook(param.win, 2, 1L << 0, key_event, &param);
	mlx_hook(param.win, 17, 0, closer, &param);
	put(&param);
	mlx_loop(param.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:57:43 by thrio             #+#    #+#             */
/*   Updated: 2023/01/17 16:43:43 by thrio            ###   ########.fr       */
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
	mlx_destroy_image(param->mlx, param->image.Chest);
	mlx_destroy_image(param->mlx, param->image.Char);
	mlx_destroy_image(param->mlx, param->image.Rock);
	mlx_destroy_image(param->mlx, param->image.Grass);
	mlx_destroy_image(param->mlx, param->image.House);
	mlx_destroy_window(param->mlx, param->win);
	mlx_destroy_display(param->mlx);
	ft_freemap(param);
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
	t_program	test;

	if (ac != 2)
		return (0);
	test.nbline = 0;
	test.nbrs.depcount = 0;
	map_init(&test, av);
	test.mlx = mlx_init();
	if (!test.mlx)
		exit(1);
	set_image(&test);
	test.win = mlx_new_window(test.mlx, test.startx, test.starty, "so_long");
	mlx_key_hook(test.win, &key_event, &test);
	mlx_hook(test.win, 17, 0, closer, &test);
	put(&test);
	mlx_loop(test.mlx);
}

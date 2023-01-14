/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:57:43 by thrio             #+#    #+#             */
/*   Updated: 2023/01/14 20:46:04 by thrio            ###   ########.fr       */
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
			if (test->map[j][n] == '1')
				mlx_put_image_to_window(test->mlx, test->win, test->image.Rock, x, y);
			else if (test->map[j][n] == 'P')
				mlx_put_image_to_window(test->mlx, test->win, test->image.Char, x, y);

			else if (test->map[j][n] == 'C')
				mlx_put_image_to_window(test->mlx, test->win, test->image.Chest, x, y);

			else if (test->map[j][n] == 'E')
				mlx_put_image_to_window(test->mlx, test->win, test->image.House, x, y);

			else if (test->map[j][n] == '0')
				mlx_put_image_to_window(test->mlx, test->win, test->image.Grass, x, y);
			n++;
			x += 32;
		}
		y+=32;
		j++;
	}
	return (0);
}

int	closer(t_program *test)
{
	mlx_destroy_window(test->mlx, test->win);
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

int key_event(int button, t_program *param)
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
	t_program test;
	
	if (ac != 2)
		return (0);
	test.mlx = mlx_init();
	if (!test.mlx)
		exit(1);
	set_image(&test);
	map_init(&test, av);
	test.win = mlx_new_window(test.mlx, test.startx - 32, test.starty, "so_long");
	mlx_key_hook(test.win, &key_event, &test);
	mlx_hook(test.win, 17, 0, closer, &test);
	put(&test);
	mlx_loop(test.mlx);
}

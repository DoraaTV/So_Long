/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:57:43 by thrio             #+#    #+#             */
/*   Updated: 2023/01/06 15:55:40 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

int mouse_event(int button, int x, int y, void *param)
{
    // Whenever the event is triggered, print the value of button to console.
	(void)param;
	int	i = 0;
	int	j = 0;
	t_program *test = param;
	
	if (button == 65307)
	{
		exit(0);
	}
	if (button == 1)
	{
		while (i < 5)
		{
			j = 0;
			while (j < 5)
			{
				mlx_pixel_put(test->mlx, test->win, x + j, y + i, 0xFF0000);
				j++;
			}
			i++;
		}
		mlx_pixel_put(test->mlx, test->win, x, y, 0xFF0000);
	}
    printf("%d\n", button);
	return (0);
}

int	put(t_program *test)
{
	mlx_put_image_to_window(test->mlx, test->win, test->image, 640/2, 360/2);
	return (0);
}

int	main()
{
	int j = 0;
	int	i = 0;
	int h = 32;
	int w = 32;
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 640, 360, "so_long");
	t_program test;
	test.mlx = mlx;
	test.win = win;
	while (i < 2000)
	{
		mlx_pixel_put(mlx, win, i, i, 0xFF0000);
		i++;
	}
	i = 200;
	while (i > 0)
	{
		mlx_pixel_put(mlx, win, j, i, 0xFF0000);
		i--;
		j++;
	}
	mlx_mouse_hook(win, &mouse_event, &test);
	mlx_key_hook(win, &mouse_event, &test);
	test.image = mlx_new_image(mlx, 15, 15);
	test.image = mlx_xpm_file_to_image(mlx, "image/Rock.xpm", &w, &h);
	mlx_loop_hook(mlx, &put, &test);
	mlx_loop(mlx);
}

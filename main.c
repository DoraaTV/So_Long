/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:57:43 by thrio             #+#    #+#             */
/*   Updated: 2023/01/09 17:06:44 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

int	closer(t_program *test)
{
	mlx_destroy_window(test->mlx, test->win);
	return (0);
}

int mouse_event(int button, int x, int y, void *param)
{
    // Whenever the event is triggered, print the value of button to console.
	(void)param;
	int	i = 0;
	int	j = 0;
	t_program *test = param;
	if (button == 17)
		closer(test);
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
	int	x;
	int	y;
	int	i;

	i = -1;	
	x = 0;
	y = 0;
	if (test->sizex > 0)
	{
		while (++i < test->sizex)
			x+=32;
	}
	i = -1;
	if (test->sizey > 0)
	{
		while (++i < test->sizey)
			y+=32;
	}
	test->sizex += 1;
	if (test->sizex == 20)
	{
		test->sizex = 0;
		if (test->sizey != 10)
			test->sizey += 1;
	}
	mlx_put_image_to_window(test->mlx, test->win, test->image, x, y);
	return (0);
}

int	main()
{
	int h = 32;
	int w = 32;
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 640, 360, "so_long");
	t_program test;
	test.sizex = 0;
	test.sizey = 0;
	test.mlx = mlx;
	test.win = win;
	mlx_mouse_hook(win, &mouse_event, &test);
	mlx_key_hook(win, &mouse_event, &test);
	test.image = mlx_new_image(mlx, 15, 15);
	test.image = mlx_xpm_file_to_image(mlx, "image/Rock.xpm", &w, &h);
	mlx_hook(test.win, 2, 1L>>17, closer, &test);

	mlx_hook(test.win, 17, 0, closer, &test);
	mlx_loop_hook(mlx, &put, &test);
	mlx_loop(mlx);
}

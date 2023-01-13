/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:57:43 by thrio             #+#    #+#             */
/*   Updated: 2023/01/13 17:53:09 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minilibx-linux/mlx.h"
# include "so_long.h"

int	put(t_program *test)
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	n;
	int	size;
	char	**map;

	i = -1;	
	x = 0;
	y = 0;
	j = 0;
	size = 32;
	map = test->map;
	while (map[j])
	{
		n = 0;
		x = 0;
		while (map[j][n])
		{
			if (map[j][n] == '1')
			{
				test->image = mlx_new_image(test->mlx, 32, 32);
				test->image = mlx_xpm_file_to_image(test->mlx, "image/Rock.xpm", &size, &size);
			}
			else if (map[j][n] == 'P')
			{
				test->image = mlx_new_image(test->mlx, 32, 32);
				test->image = mlx_xpm_file_to_image(test->mlx, "image/Char.xpm", &size, &size);
			}
			else if (map[j][n] == 'C')
			{
				test->image = mlx_new_image(test->mlx, 32, 32);
				test->image = mlx_xpm_file_to_image(test->mlx, "image/Chest.xpm", &size, &size);
			}
			else if (map[j][n] == 'E')
			{
				test->image = mlx_new_image(test->mlx, 32, 32);
				test->image = mlx_xpm_file_to_image(test->mlx, "image/House.xpm", &size, &size);
			}
			else if (map[j][n] == '0')
			{
				test->image = mlx_new_image(test->mlx, 32, 32);
				test->image = mlx_xpm_file_to_image(test->mlx, "image/Grass.xpm", &size, &size);
			}
			n++;
			mlx_put_image_to_window(test->mlx, test->win, test->image, x, y);
			x += 32;
			test->sizex += 1;
		}
		test->sizey += 1;
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

int key_event(int button, t_program *param)
{
    // Whenever the event is triggered, print the value of button to console.
	int	i = 0;
	int	j = 0;
	int	buf = 0;

	if (button == 65307)
		closer(param);
	else if (button == 119 || button == 65362)
	{
		while (param->map[i] && buf == 0)
		{
			j = 0;
			while (j <= param->size)
			{
				if (param->map[i][j] == 'P' && param->map[i - 1][j] != '1' && param->map[i - 1][j] != 'E')
				{
					param->map[i - 1][j] = 'P';
					param->map[i][j] = '0';
					buf = 1;
					break;
				}
				j++;
			}
			i++;
		}
		//mlx_clear_window(param->mlx, param->win);
		put(param);
	}
	else if (button == 100 || button == 65363)
	{
		while (param->map[i] && buf == 0)
		{
			j = 0;
			while (j <= param->size)
			{
				if (param->map[i][j] == 'P' && param->map[i][j + 1] != '1' && param->map[i][j + 1] != 'E')
				{
					param->map[i][j + 1] = 'P';
					param->map[i][j] = '0';
					buf = 1;
					break;
				}
				j++;
			}
			i++;
		}
		//mlx_clear_window(param->mlx, param->win);
		put(param);
	}
	else if (button == 97 || button == 65361)
	{
		while (param->map[i] && buf == 0)
		{
			j = 0;
			while (j <= param->size)
			{
				if (param->map[i][j] == 'P' && param->map[i][j - 1] != '1' && param->map[i][j - 1] != 'E')
				{
					param->map[i][j - 1] = 'P';
					param->map[i][j] = '0';
					buf = 1;
					break;
				}
				j++;
			}
			i++;
		}
		//mlx_clear_window(param->mlx, param->win);
		put(param);
	}
	else if (button == 115 || button == 65364)
	{
		while (param->map[i] && buf == 0)
		{
			j = 0;
			while (j <= param->size)
			{
				if (param->map[i][j] == 'P' && param->map[i + 1][j] != '1' && param->map[i + 1][j] != 'E')
				{
					param->map[i + 1][j] = 'P';
					param->map[i][j] = '0';
					buf = 1;
					break;
				}
				j++;
			}
			i++;
		}
		//mlx_clear_window(param->mlx, param->win);
		put(param);
	}
    printf("%d\n", button);
	return (0);
}



int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	t_program test;
	void *mlx = mlx_init();
	char *map;
	int	fd = open(av[1], O_RDONLY);
	int	i = 0;
	map = get_next_line(fd);
	test.map = malloc(sizeof(char *) * ft_strlen(map));
	int	sizex = ft_strlen(map);
	while (map)
	{
		test.map[i] = malloc(sizeof(char) * sizex);
		test.map[i] = map;
		map = get_next_line(fd);
		i++;
	}
	i = 0;
	int	startx = 32 * ft_strlen(test.map[i]);
	int	starty = 0;
	while (test.map[i])
	{
		starty += 32;
		i++;
	}
	void *win = mlx_new_window(mlx, startx - 32, starty, "so_long");
	test.size = sizex;
	test.sizex = 0;
	test.sizey = 0;
	test.mlx = mlx;
	test.win = win;
	mlx_key_hook(test.win, &key_event, &test);
	mlx_hook(test.win, 17, 0, closer, &test);
	put(&test);
	mlx_loop(test.mlx);
}

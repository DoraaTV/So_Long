/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:49:43 by thrio             #+#    #+#             */
/*   Updated: 2023/01/17 19:38:19 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../includes/so_long.h"

void casefalse(char *map, int fd)
{
    while (map)
		map = get_next_line(fd);
	free(map);
	exit(1);
}

void	closererror(t_program *param)
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
	free(param->mlx);
	ft_printf("The map contain an unknow character");
	exit(1);
}

void	notenoughc(t_program *test)
{
	ft_printf("There is no collectible, one collectible or more are required\n");
	ft_freemap(test);
	exit(1);
}

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
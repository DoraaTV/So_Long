/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:49:43 by thrio             #+#    #+#             */
/*   Updated: 2023/01/18 20:30:49 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../includes/so_long.h"

void	string_put(t_program *test)
{
	char	*s;
	char	*nb;

	nb = ft_itoa(test->nbrs.depcount);
	s = malloc(sizeof(char) * 8);
	s = "Moves :";
	s = ft_strjoin(s, nb);
	mlx_string_put(test->mlx, test->win, 15, 15, 0x0000FF00, s);
	free(s);
	free(nb);
}

void	casefalse(char *map, int fd)
{
	while (map)
		map = get_next_line(fd);
	free(map);
	exit(1);
}

void	closererror(t_program *param)
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
		mlx_put_image_to_window(test->mlx, test->win, test->image.rock, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(test->mlx, test->win, test->image.player, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(test->mlx, test->win, test->image.chest, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(test->mlx, test->win, test->image.house, x, y);
	else if (c == '0')
		mlx_put_image_to_window(test->mlx, test->win, test->image.grass, x, y);
}

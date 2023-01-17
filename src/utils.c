/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:49:43 by thrio             #+#    #+#             */
/*   Updated: 2023/01/17 19:22:58 by thrio            ###   ########.fr       */
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
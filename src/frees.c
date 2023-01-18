/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:04:55 by thrio             #+#    #+#             */
/*   Updated: 2023/01/18 19:25:04 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"

void	ft_freeone(t_program *param)
{
	ft_printf("The chest xpm file is missing");
	mlx_destroy_display(param->mlx);
	ft_freemap(param);
	free(param->mlx);
	exit(1);
}

void	ft_freetwo(t_program *param)
{
	mlx_destroy_image(param->mlx, param->image.chest);
	ft_printf("The char xpm file is missing");
	mlx_destroy_display(param->mlx);
	ft_freemap(param);
	free(param->mlx);
	exit(1);
}

void	ft_freethree(t_program *param)
{
	mlx_destroy_image(param->mlx, param->image.chest);
	mlx_destroy_image(param->mlx, param->image.player);
	ft_printf("The Rock xpm file is missing");
	mlx_destroy_display(param->mlx);
	ft_freemap(param);
	free(param->mlx);
	exit(1);
}

void	ft_freefour(t_program *param)
{
	mlx_destroy_image(param->mlx, param->image.chest);
	mlx_destroy_image(param->mlx, param->image.player);
	mlx_destroy_image(param->mlx, param->image.rock);
	ft_printf("The Grass xpm file is missing");
	mlx_destroy_display(param->mlx);
	ft_freemap(param);
	free(param->mlx);
	exit(1);
}

void	ft_freefive(t_program *param)
{
	mlx_destroy_image(param->mlx, param->image.chest);
	mlx_destroy_image(param->mlx, param->image.player);
	mlx_destroy_image(param->mlx, param->image.rock);
	mlx_destroy_image(param->mlx, param->image.grass);
	ft_printf("The House xpm file is missing");
	mlx_destroy_display(param->mlx);
	ft_freemap(param);
	free(param->mlx);
	exit(1);
}

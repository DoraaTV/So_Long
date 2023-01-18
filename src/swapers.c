/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:51:53 by thrio             #+#    #+#             */
/*   Updated: 2023/01/18 20:11:45 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	firstcheck(char **map, int i, int j)
{
	if (map[i + 1][j] != '1' && (map[i + 1][j] == '0'
		|| map[i + 1][j] == 'C' || map[i + 1][j] == 'E'))
	{
		map[i + 1][j] = '3';
		firstcheck(map, i + 1, j);
	}
	if ((map[i - 1][j] == '0' || map[i - 1][j] == 'C'))
	{
		map[i - 1][j] = '3';
		firstcheck(map, i - 1, j);
	}
	if ((map[i][j + 1] == '0' || map[i][j + 1] == 'C'))
	{
		map[i][j + 1] = '3';
		firstcheck(map, i, j + 1);
	}
	if ((map[i][j - 1] == '0' || map[i][j - 1] == 'C'))
	{
		map[i][j - 1] = '3';
		firstcheck(map, i, j - 1);
	}
}

void	swapiplus(t_program *param, int i, int j, int *buf)
{
	param->map[i + 1][j] = 'P';
	param->map[i][j] = '0';
	param->nbrs.depcount++;
	ft_printf("count : %d\n", param->nbrs.depcount);
	*buf = 1;
}

void	swapimoins(t_program *param, int i, int j, int *buf)
{
	param->map[i - 1][j] = 'P';
	param->map[i][j] = '0';
	param->nbrs.depcount++;
	ft_printf("count : %d\n", param->nbrs.depcount);
	*buf = 1;
}

void	swapjplus(t_program *param, int i, int j, int *buf)
{
	param->map[i][j + 1] = 'P';
	param->map[i][j] = '0';
	param->nbrs.depcount++;
	ft_printf("count : %d\n", param->nbrs.depcount);
	*buf = 1;
}

void	swapjmoins(t_program *param, int i, int j, int *buf)
{
	param->map[i][j - 1] = 'P';
	param->map[i][j] = '0';
	param->nbrs.depcount++;
	ft_printf("count : %d\n", param->nbrs.depcount);
	*buf = 1;
}

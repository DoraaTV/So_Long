/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:51:53 by thrio             #+#    #+#             */
/*   Updated: 2023/01/17 16:44:37 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	swapiplus(t_program *param, int i, int j, int *buf)
{
	param->map[i + 1][j] = 'P';
	param->map[i][j] = '0';
	param->nbrs.depcount++;
	*buf = 1;
}

void	swapimoins(t_program *param, int i, int j, int *buf)
{
	param->map[i - 1][j] = 'P';
	param->map[i][j] = '0';
	param->nbrs.depcount++;
	*buf = 1;
}

void	swapjplus(t_program *param, int i, int j, int *buf)
{
	param->map[i][j + 1] = 'P';
	param->map[i][j] = '0';
	param->nbrs.depcount++;
	*buf = 1;
}

void	swapjmoins(t_program *param, int i, int j, int *buf)
{
	param->map[i][j - 1] = 'P';
	param->map[i][j] = '0';
	param->nbrs.depcount++;
	*buf = 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:00:53 by thrio             #+#    #+#             */
/*   Updated: 2023/01/14 14:04:23 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    move_up(t_program *param)
{
    int i;
    int j;
    int buf;

    i = 0;
    buf = 0;
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
				if (param->map[i][j] == 'P' && param->map[i - 1][j] == 'E' && is_finished(param))
				{
					printf("Felicitation ! Vous avez gagne !");
					closer(param);
				}
				j++;
			}
			i++;
		}
        put(param);
}
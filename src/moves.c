/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:00:53 by thrio             #+#    #+#             */
/*   Updated: 2023/01/18 19:07:14 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	casewin(t_program *param)
{
	param->nbrs.depcount++;
	ft_printf("You won with %d moves !", param->nbrs.depcount);
	closer(param);
}

void	move_up(t_program *param)
{
	int	i;
	int	j;
	int	buf;

	i = -1;
	buf = 0;
	while (param->map[++i] && buf == 0)
	{
		j = -1;
		while (++j <= param->size - 1 && buf == 0)
		{
			if (param->map[i][j] == 'P')
			{
				if (param->map[i - 1][j] != '1' && param->map[i - 1][j] != 'E')
					swapimoins(param, i, j, &buf);
				else if (param->map[i - 1][j] == 'E' && is_finished(param))
					casewin(param);
			}
		}
	}
	put(param);
}

void	move_right(t_program *param)
{
	int	i;
	int	j;
	int	buf;

	i = -1;
	buf = 0;
	while (param->map[++i] && buf == 0)
	{
		j = -1;
		while (++j <= param->size - 1 && buf == 0)
		{
			if (param->map[i][j] == 'P')
			{
				if (param->map[i][j + 1] != '1' && param->map[i][j + 1] != 'E')
					swapjplus(param, i, j, &buf);
				else if (param->map[i][j + 1] == 'E' && is_finished(param))
					casewin(param);
			}
		}
	}
	put(param);
}

void	move_left(t_program *param)
{
	int	i;
	int	j;
	int	buf;

	i = -1;
	buf = 0;
	while (param->map[++i] && buf == 0)
	{
		j = -1;
		while (++j <= param->size - 1)
		{
			if (param->map[i][j] == 'P')
			{
				if (param->map[i][j - 1] != '1' && param->map[i][j - 1] != 'E')
					swapjmoins(param, i, j, &buf);
				if (param->map[i][j - 1] == 'E' && is_finished(param))
					casewin(param);
			}
		}
	}
	put(param);
}

void	move_down(t_program *param)
{
	int	i;
	int	j;
	int	buf;

	i = -1;
	buf = 0;
	while (param->map[++i] && buf == 0)
	{
		j = -1;
		while (++j <= param->size - 1 && buf == 0)
		{
			if (param->map[i][j] == 'P')
			{
				if (param->map[i + 1][j] != '1' && param->map[i + 1][j] != 'E')
					swapiplus(param, i, j, &buf);
				else if (param->map[i + 1][j] == 'E' && is_finished(param))
					casewin(param);
			}
		}
	}
	put(param);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:46:14 by thrio             #+#    #+#             */
/*   Updated: 2023/01/18 20:13:49 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_validpathone(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				return (0);
		}
	}
	return (1);
}

void	fd_not_exist(void)
{
	ft_printf("The file is not found\n");
	exit(1);
}

void	file_name_not_good(void)
{
	ft_printf("The file name does not meet requirement\
 (less than 5 characters\n");
	exit(1);
}

void	no_ber(void)
{
	ft_printf("The file is not a .ber\n");
	exit(1);
}

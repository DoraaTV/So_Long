/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:16:54 by thrio             #+#    #+#             */
/*   Updated: 2023/01/14 20:26:07 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"

void	set_image(t_program *param)
{
	int size;

	size = 32;
	param->image.Chest = mlx_xpm_file_to_image(param->mlx, "image/Chest.xpm", &size, &size);
	param->image.Char = mlx_xpm_file_to_image(param->mlx, "image/Char.xpm", &size, &size);
	param->image.Rock = mlx_xpm_file_to_image(param->mlx, "image/Rock.xpm", &size, &size);
	param->image.Grass = mlx_xpm_file_to_image(param->mlx, "image/Grass.xpm", &size, &size);
	param->image.House = mlx_xpm_file_to_image(param->mlx, "image/House.xpm", &size, &size);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		diff;	

	i = 0;
	diff = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			diff = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (diff);
		}
		i++;
	}
	return (diff);
}

void	fd_checker(int fd, char **file)
{
	if (fd <= 2)
		exit(1);
	if (ft_strlen(file[1]) < 5)
		exit(1);
	if (ft_strncmp(file[1] + (ft_strlen(file[1]) - 4), ".ber", 4) != 0)
		exit(1);
}

void	map_init(t_program *param, char **file)
{
	int		fd;
	int		i;
	int		j;
	char	*map;

	i = -1;
	j = -1;
	fd = open(file[1], O_RDONLY);
	fd_checker(fd, file);
	map = get_next_line(fd);
	param->map = malloc(sizeof(char *) * ft_strlen(map));
	param->size = ft_strlen(map);
	while (map)
	{
		param->map[++i] = malloc(sizeof(char) * param->size);
		param->map[i] = map;
		map = get_next_line(fd);
	}
	param->startx = 32 * param->size;
	param->starty = 0;
	while (param->map[++j])
		param->starty += 32;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:16:54 by thrio             #+#    #+#             */
/*   Updated: 2023/01/18 19:22:33 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"

void	ft_freemap(t_program *param)
{
	int	i;

	i = 0;
	while (param->map[i])
	{
		free(param->map[i]);
		i++;
	}
	free(param->map);
}

void	set_image(t_program *p)
{
	int	s;

	s = 32;
	p->image.chest = mlx_xpm_file_to_image(p->mlx, "image/Chest.xpm", &s, &s);
	if (!p->image.chest)
		ft_freeone(p);
	p->image.player = mlx_xpm_file_to_image(p->mlx, "image/Char.xpm", &s, &s);
	if (!p->image.player)
		ft_freetwo(p);
	p->image.rock = mlx_xpm_file_to_image(p->mlx, "image/Rock.xpm", &s, &s);
	if (!p->image.rock)
		ft_freethree(p);
	p->image.grass = mlx_xpm_file_to_image(p->mlx, "image/Grass.xpm", &s, &s);
	if (!p->image.grass)
		ft_freefour(p);
	p->image.house = mlx_xpm_file_to_image(p->mlx, "image/House.xpm", &s, &s);
	if (!p->image.house)
		ft_freefive(p);
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
		fd_not_exist();
	if (ft_strlen(file[1]) < 5)
		file_name_not_good();
	if (ft_strncmp(file[1] + (ft_strlen(file[1]) - 4), ".ber", 4) != 0)
		no_ber();
}

void	map_init(t_program *param, char **file)
{
	int		fd;
	int		i;
	char	*line;
	char	*buf;
	char	*store;

	i = 0;
	fd = open(file[1], O_RDONLY);
	fd_checker(fd, file);
	line = get_next_line(fd);
	store = ft_strdup("");
	param->size = ft_strlen(line);
	while (line)
	{
		buf = store;
		store = ft_strjoin(buf, line);
		free(buf);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	param->map = ft_split(store, '\n');
	free(store);
	ft_helper(param, i, fd);
}

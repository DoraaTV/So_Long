/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:38:55 by thrio             #+#    #+#             */
/*   Updated: 2023/01/14 14:04:50 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct  s_program
{
    char **map;
    void *mlx;
    void *win;
    void *image;
    int size;
    int sizex;
    int sizey;
}               t_program;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*dofree(char *res, char *buffer);
char	*getnext(char *buffer);
char	*getmyline(char *buffer);
char	*reader(int fd, char *res);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int	closer(t_program *test);
void    move_up(t_program *param);
int	is_finished(t_program *param);
int	put(t_program *test);

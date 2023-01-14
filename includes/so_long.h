/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:38:55 by thrio             #+#    #+#             */
/*   Updated: 2023/01/14 15:41:22 by thrio            ###   ########.fr       */
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
    int startx;
    int starty;
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
# include <stdarg.h>

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
int	ft_printf(const char *str, ...);
int	ft_putchar_int(char c);
int	ft_putstr_int(char *s);
int	ft_checker(char c, va_list s);
int	ft_putnbr_base(long unsigned int nb, char *base);
int	ft_print_p(long unsigned int nb);
int	ft_putnbr_int(long int nbr);
int	ft_printxx(long long int nb, char c);
void move_right(t_program *param);
void	swapiplus(t_program *param, int i, int j, int *buf);
void	swapjplus(t_program *param, int i, int j, int *buf);
void	swapimoins(t_program *param, int i, int j, int *buf);
void	swapjmoins(t_program *param, int i, int j, int *buf);
void	move_left(t_program *param);
void	move_down(t_program *param);
void    map_init(t_program *param, char **file);

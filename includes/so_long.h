/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:38:55 by thrio             #+#    #+#             */
/*   Updated: 2023/01/18 19:29:32 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

/*----INCLUDES----*/

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>

/*----STRUCTS-----*/

typedef struct j_program
{
	int	exitnb;
	int	charnb;
	int	depcount;
	int	ccount;
}				t_numbers;

typedef struct r_program
{
	void	*chest;
	void	*house;
	void	*rock;
	void	*grass;
	void	*player;
}				t_image;

typedef struct s_program
{
	char		**map;
	void		*mlx;
	void		*win;
	int			size;
	int			nbline;
	int			startx;
	int			starty;
	t_image		image;
	t_numbers	nbrs;
}				t_program;

/*----PROTOTYPES----*/

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
int		closer(t_program *param);
void	move_up(t_program *param);
int		is_finished(t_program *param);
int		put(t_program *test);
int		ft_printf(const char *str, ...);
int		ft_putchar_int(char c);
int		ft_putstr_int(char *s);
int		ft_checker(char c, va_list s);
int		ft_putnbr_base(long unsigned int nb, char *base);
int		ft_print_p(long unsigned int nb);
int		ft_putnbr_int(long int nbr);
int		ft_printxx(long long int nb, char c);
void	move_right(t_program *param);
void	swapiplus(t_program *param, int i, int j, int *buf);
void	swapjplus(t_program *param, int i, int j, int *buf);
void	swapimoins(t_program *param, int i, int j, int *buf);
void	swapjmoins(t_program *param, int i, int j, int *buf);
void	move_left(t_program *param);
void	move_down(t_program *param);
void	map_init(t_program *param, char **file);
void	set_image(t_program *p);
void	fd_not_exist(void);
void	file_name_not_good(void);
void	no_ber(void);
void	map_checker(t_program *param);
void	ft_freemap(t_program *param);
void	ft_freeone(t_program *param);
void	ft_freetwo(t_program *param);
void	ft_freethree(t_program *param);
void	ft_freefour(t_program *param);
void	ft_freefive(t_program *param);
void	whichchar(char c, int x, int y, t_program *test);
void	casefalse(char *map, int fd);
void	not_rectangle(t_program *test);
void	closererror(t_program *param);
void	notenoughc(t_program *test);
void	cornercheck(t_program *param);
void	string_put(t_program *test);
char	*ft_itoa(int n);
void	pathfinding(t_program *param);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *src);
void	ft_helper(t_program *param, int i, int fd);

#endif
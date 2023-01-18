/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:55:15 by thrio             #+#    #+#             */
/*   Updated: 2023/01/18 16:39:16 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	size_t			i;
	size_t			j;

	j = 0;
	i = start;
	if (start > ft_strlen(s))
		res = malloc(sizeof(char));
	else if (len < ft_strlen(s + i))
		res = malloc(sizeof(char) * (len + 1));
	else
		res = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (!res)
		return (NULL);
	while (!(start > ft_strlen(s)) && s[i] && j < len)
	{
		res[j] = s[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			counter++;
			while (s[i] && c != s[i])
				i++;
		}
		else
			i++;
	}
	return (counter);
}

static size_t	lettercount(const char *s, char c, size_t i)
{
	size_t	size;

	size = 0;
	while (s[i] && s[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

static void	*dofrees(char **res, int j)
{
	while (j-- > 0)
		free(res[j]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**res;
	size_t	nb_mot;
	size_t	size;

	i = 0;
	j = -1;
	nb_mot = count_word(s, c);
	res = (char **)malloc(sizeof(char *) * (nb_mot + 1));
	if (!res)
		return (NULL);
	while (++j < nb_mot)
	{
		while (s[i] == c)
			i++;
		size = lettercount(s, c, i);
		res[j] = ft_substr(s, i, size);
		if (!res[j])
			return (dofrees(res, j));
		i += size;
	}
	res[j] = 0;
	return (res);
}

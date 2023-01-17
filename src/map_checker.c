/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:56:05 by thrio             #+#    #+#             */
/*   Updated: 2023/01/15 18:40:10 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    too_much_char(t_program *test)
{
    int i;

    i = 0;
    ft_printf("There is no or too much character, only one character is required\n");
    while (test->map[i])
	{
		free(test->map[i]);	
		i++;
	}
	free(test->map);
    exit (1);
}

void    too_much_exit(t_program *test)
{
    int i;

    i = 0;
    ft_printf("There is no or too much exit, only one exit is required\n");
    while (test->map[i])
	{
		free(test->map[i]);	
		i++;
	}
	free(test->map);
    exit (1);
}

void    not_rectangle(t_program *test)
{
    int i;

    i = 0;
    ft_printf("The map is not a rectangle\n");
    while (test->map[i])
	{
		free(test->map[i]);	
		i++;
	}
	free(test->map);
    exit (1);
}

void map_checker(t_program *param)
{
    int i;
    int j;

    i = 0;
    param->nbrs.charnb = 0;
    param->nbrs.exitnb = 0;
    while (param->map[i])
    {
        j = 0;
        while (param->map[i][j])
        {
            if (param->map[i][j] == 'P')
                param->nbrs.charnb += 1;
            else if (param->map[i][j] == 'E')
                param->nbrs.exitnb += 1;
            j++;
        }
        if (i + 1 != param->nbline && j != param->size)
            not_rectangle(param);
        else if (i + 1 == param->nbline && j + 1 != param->size)
            not_rectangle(param);
        i++;
    }
    if (param->nbrs.charnb != 1)
        too_much_char(param);
    else if (param->nbrs.exitnb != 1)
        too_much_exit(param);
}
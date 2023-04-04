/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:21:59 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/04/04 15:22:01 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include "get_next_line.h"
#include <stdio.h>

void	player_pos(t_game *gm)
{
	int	i;
	int	j;

	i = 0;
	while (gm->map[i])
	{
		j = 0;
		while (gm->map[i][j])
		{
			if (gm->map[i][j] == 'P')
			{
				gm->x = i;
				gm->y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	check_exit(int n)
{
	if (n == 1)
		write(1, "The map must be rectangular!\n", 29);
	else if (n == 2)
		write(1, "The map may include only 0, 1, E, C, P!\n", 40);
	else if (n == 3)
		write(1, "The map may include only one E and P!\n", 38);
	else
		write(1, "The map must be surrounded by walls!\n", 37);
	exit(1);
}

void	check_border(t_game *gm)
{
	int	j;
	int	i;

	j = 0;
	while (gm->map[0][j])
		if (gm->map[0][j++] != '1')
			check_exit(0);
	j = 0;
	while (gm->map[j] != NULL)
		if (gm->map[j++][0] != '1')
			check_exit(0);
	j = 0;
	while (gm->map[j] != NULL)
		if (gm->map[j++][ft_strlen(gm->map[0]) - 1] != '1')
			check_exit(0);
	i = j;
	j = 0;
	while (gm->map[i - 1][j])
		if (gm->map[i - 1][j++] != '1')
			check_exit(0);
}

void	check_rectangular(t_game *gm)
{
	int	j;
	int	len;

	len = ft_strlen(gm->map[0]);
	j = 0;
	while (gm->map[j] != NULL)
		if (len != ft_strlen(gm->map[j++]))
			check_exit(1);
}

void	check_symbol(t_game *gm)
{
	int	i;
	int	j;
	int	count_p;
	int	count_e;

	i = -1;
	count_p = 0;
	count_e = 0;
	while (gm->map[++i])
	{
		j = 0;
		while (gm->map[i][j])
		{
			if (gm->map[i][j] != 'P' && gm->map[i][j] != '1' && \
				gm->map[i][j] != '0' && gm->map[i][j] != 'E' && \
				gm->map[i][j] != 'C')
				check_exit(2);
			if (gm->map[i][j] == 'P')
				count_p++;
			if (gm->map[i][j++] == 'E')
				count_e++;
		}
	}
	if (count_p > 1 || count_e > 1)
		check_exit(3);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:04:01 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/04/03 17:04:02 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "get_next_line.h"
#include <stdio.h>

void	move_left(t_game *gm)
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
				gm->map[i][j - 1] = 'P';
				gm->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_right(t_game *gm)
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
				gm->map[i][j + 1] = 'P';
				gm->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_up(t_game *gm)
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
				gm->map[i - 1][j] = 'P';
				gm->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_down(t_game *gm)
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
				gm->map[i + 1][j] = 'P';
				gm->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	exit_game()
{
	exit(1);
}

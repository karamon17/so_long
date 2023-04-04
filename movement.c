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
	player_pos(gm);
	gm->map[gm->x][gm->y - 1] = 'P';
	gm->map[gm->x][gm->y] = '0';
}

void	move_right(t_game *gm)
{
	player_pos(gm);
	gm->map[gm->x][gm->y + 1] = 'P';
	gm->map[gm->x][gm->y] = '0';
}

void	move_up(t_game *gm)
{
	player_pos(gm);
	gm->map[gm->x - 1][gm->y] = 'P';
	gm->map[gm->x][gm->y] = '0';

}

void	move_down(t_game *gm)
{
	player_pos(gm);
	gm->map[gm->x + 1][gm->y] = 'P';
	gm->map[gm->x][gm->y] = '0';
}

void	exit_game()
{
	exit(1);
}

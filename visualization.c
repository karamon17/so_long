/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:11:06 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/04/03 11:11:08 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include "get_next_line.h"
#include <stdio.h>

void player_pos(t_game *gm)
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

void init_image(t_game *gm)
{
	gm->start = mlx_xpm_file_to_image(gm->mlx, "start.xpm", &gm->wid, &gm->hei);
	gm->finish = mlx_xpm_file_to_image(gm->mlx, "finish.xpm", &gm->wid, &gm->hei);
	gm->wall = mlx_xpm_file_to_image(gm->mlx, "wall.xpm", &gm->wid, &gm->hei);
	gm->heart = mlx_xpm_file_to_image(gm->mlx, "heart.xpm", &gm->wid, &gm->hei);
}

void	ft_image(t_game *gm)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(gm->mlx, gm->win);
	while (gm->map[i])
	{
		j = 0;
		while (gm->map[i][j])
		{
			if (gm->map[i][j] == '1')
				mlx_put_image_to_window(gm->mlx, gm->win, gm->wall, j * 64, i * 64);
			if (gm->map[i][j] == 'P')
				mlx_put_image_to_window(gm->mlx, gm->win, gm->start, j * 64, i * 64);
			if (gm->map[i][j] == 'C')
				mlx_put_image_to_window(gm->mlx, gm->win, gm->heart, j * 64, i * 64);
			if (gm->map[i][j] == 'E')
				mlx_put_image_to_window(gm->mlx, gm->win, gm->finish, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

int handle_key_press(int keycode, t_game *gm)
{
    if (keycode == 13) // 'W' key
		move_up(gm);
	else if (keycode == 0) // 'A' key
		move_left(gm);
	else if (keycode == 1) // 'S' key
		move_down(gm);
	else if (keycode == 2) // 'D' key
		move_right(gm);
	else if (keycode == 53)
		exit_game();
	ft_image(gm);
    return (0);
}

void	ft_visualization(t_game *gm)
{
	int		i;
	
	i = 0;
	gm->w_field = 64 * ft_strlen(gm->map[0]);
	while (gm->map[i])
		i++;
	gm->h_field = 64 * i;
	gm->mlx = mlx_init();
	gm->win = mlx_new_window(gm->mlx, gm->w_field, \
		gm->h_field, "so_long");
	init_image(gm);
	ft_image(gm);
	mlx_hook(gm->win, 2, 0, handle_key_press, gm);
	mlx_loop(gm->mlx);
}

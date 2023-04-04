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

// void player_pos(t_game *game)
// {}

void init_image(t_game *gm)
{
	gm->start = mlx_xpm_file_to_image(gm->mlx, "start->xpm", &gm->wid, &gm->hei);
	gm->finish = mlx_xpm_file_to_image(gm->mlx, "finish->xpm", &gm->wid, &gm->hei);
	gm->wall = mlx_xpm_file_to_image(gm->mlx, "wall->xpm", &gm->wid, &gm->hei);
	gm->heart = mlx_xpm_file_to_image(gm->mlx, "heart->xpm", &gm->wid, &gm->hei);
}

void	ft_image(t_game *gm)
{

init_image(gm);
	int	i;
	int	j;
printf("%d\n",__LINE__);
	i = 0;
	mlx_clear_window(gm->mlx, gm->win);
	while (gm->map[i])
	{
		printf("%d\n",__LINE__);

		j = 0;
		while (gm->map[i][j])
		{
			printf("%d\n",__LINE__);

			if (gm->map[i][j] == '1')
				mlx_put_image_to_window(gm->mlx, gm->win, gm->wall, i * 64, j * 64);
			if (gm->map[i][j] == 'P')
				mlx_put_image_to_window(gm->mlx, gm->win, gm->start, i * 64, j * 64);
			if (gm->map[i][j] == 'C')
				mlx_put_image_to_window(gm->mlx, gm->win, gm->heart, i * 64, j * 64);
			if (gm->map[i][j] == 'E')
				mlx_put_image_to_window(gm->mlx, gm->win, gm->finish, i * 64, j * 64);
			j++;
		}
		i++;
	}
	printf("%d\n",__LINE__);
}

// void call_hook(t_game *gm)
// {

// }

void	ft_visualization(t_game *gm)
{
	int		i;
	
	i = 0;
	// int x = 0;
	// while(gm->map[x])
	// {
	// 	printf("%s\n",gm->map[x++]);
	// }
	printf("%d\n",__LINE__);
	gm->x = 0;
	gm->y = 0;
	gm->w_field = 64 * ft_strlen(gm->map[0]);
	while (gm->map[i])
		i++;
	gm->h_field = 64 * i;
	gm->mlx = mlx_init();
	gm->win = mlx_new_window(gm->mlx, gm->w_field, \
	gm->h_field, "so_long");
	printf("%d\n",__LINE__);
	printf("%d\n",__LINE__);
	ft_image(gm);
	// mlx_hook(gm->win, 2, 0, handle_key_press, &gm);
	//smap->map[0][0] = 'P';
	mlx_loop(gm->mlx);
	printf("%d\n",__LINE__);
}



int handle_key_press(int keycode, t_game *gm)
{
	
	//t_map *smap;
	
	//smap = (t_map *)param;
    if (keycode == 13) // 'W' key
		move_up(gm);
	// else if (keycode == 0) // 'A' key
	// 	move_left(smap);
	// else if (keycode == 1) // 'S' key
	// 	move_down(smap);
	// else if (keycode == 2) // 'D' key
	// 	move_right(smap);
	// else if (keycode == 53)
	// 	exit_game();
    return (0);
}
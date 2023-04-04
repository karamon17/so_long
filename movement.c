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

// void	move_left(char ***map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (*map[i])
// 	{
// 		j = 0;
// 		while (*map[i][j])
// 		{
// 			if (*map[i][j] == 'P')
// 			{	
// 				*map[i][j - 1] = 'P';
// 				*map[i][j] = '0';
// 				return ;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	move_right(char ***map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (*map[i])
// 	{
// 		j = 0;
// 		while (*map[i][j])
// 		{
// 			if (*map[i][j] == 'P')
// 			{	
// 				*map[i][j + 1] = 'P';
// 				*map[i][j] = '0';
// 				return ;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }
#include <stdio.h>
void	move_up(t_game *gm)
{
	int	i;
	int	j;

	// while (smap->map[i])
	// {
	// 	j = 0;
	// 	while (smap->map[i][j])
	// 	{
	// 		if (smap->map[i][j] == 'P')
	// 		{	
	// 			smap->map[i - 1][j] = 'P';
	// 			smap->map[i][j] = '0';
	// 			return ;
	// 		}
	// 		j++;
	// 	}
	// 	i++;
	// }
}

// void	move_down(char ***map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (*map[i])
// 	{
// 		j = 0;
// 		while (*map[i][j])
// 		{
// 			if (*map[i][j] == 'P')
// 			{	
// 				*map[i + 1][j] = 'P';
// 				*map[i][j] = '0';
// 				return ;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	exit_game()
// {
// 	//exit(1);
// }

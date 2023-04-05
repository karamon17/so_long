/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:59:43 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/04/04 16:59:48 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include "get_next_line.h"

int	check_w(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j++] == 'W')
				return (1);
		}
	}
	return (0);
}

void	check_path(char *str, t_game *gm)
{
	int		x;
	int		y;
	char	**map;

	map = ft_split(str, '\n');
	x = gm->x;
	y = gm->y;
	is_path_exists(map, x, y);
	if (!check_w(map) || !check_coin(map))
	{
		write(1, "There’s no valid path in the map!\n", 34);
		free(map);
		exit(1);
	}
	free(map);
	free(str);
}

int	is_path_exists(char **map, int x, int y)
{
	if (map[x][y] == 'E')
		map[x][y] = 'W';
	if (map[x][y] == '1' || map[x][y] == 'V' || map[x][y] == 'W')
		return (0);
	map[x][y] = 'V';
	is_path_exists(map, x + 1, y);
	is_path_exists(map, x - 1, y);
	is_path_exists(map, x, y + 1);
	is_path_exists(map, x, y - 1);
	return (0);
}

int	check_coin(char	**map)
{
	int	i;
	int	j;
	int	count_c;

	i = -1;
	count_c = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j++] == 'C')
				count_c++;
		}
	}
	if (count_c == 0)
		return (1);
	return (0);
}

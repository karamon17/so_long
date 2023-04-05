/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:05:30 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/03/31 19:05:32 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include <stdio.h>

void	continuation(t_game *gm, char *str)
{
	gm->map = ft_split(str, '\n');
	check_symbol(gm);
	check_rectangular_coins(gm);
	check_border(gm);
	player_pos(gm);
	check_path(str, gm);
	ft_visualization(gm);
}

void	check_extensions(int argc, char **argv)
{
	if (!argc || !argv[1] || !ft_strchr(argv[1], '.'))
	{
		write(1, "No extension\n", 13);
		exit(1);
	}
	if (ft_strrchr(argv[1], '.') != ft_strchr(argv[1], '.'))
	{
		write(1, "More then one extension\n", 24);
		exit(1);
	}
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber\0", 5) != 0)
	{
		write(1, "Uncomplete or too long extension\n", 33);
		exit(1);
	}
	if (ft_strrchr(argv[1], '.') == argv[1])
	{
		write(1, "Too short name of file\n", 23);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	gm;
	char	*str;
	char	*line;

	check_extensions(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "There is no such file\n", 22);
		exit(1);
	}
	line = get_next_line(fd);
	if (!line)
	{
		write(1, "Empty file\n", 11);
		exit(1);
	}
	str = ft_calloc(1, 1);
	while (line)
	{
		str = ft_strjoin(str, line);
		line = get_next_line(fd);
	}
	continuation(&gm, str);
}

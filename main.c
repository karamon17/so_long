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

int	main(int argc, char **argv)
{
	int		fd;
	t_game	gm;
	char	*str;
	char	*line;

	if (!argc || !argv[1] || !ft_strrchr(argv[1], '.'))
		exit(1);
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 4) != 0)
		exit(1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(1);
	str = ft_calloc(1, 1);
	line = get_next_line(fd);
	while (line)
	{
		str = ft_strjoin(str, line);
		line = get_next_line(fd);
	}
	gm.map = ft_split(str, '\n');
	ft_visualization(&gm);
}

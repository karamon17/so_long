/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:23:21 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/03/31 19:23:25 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>

typedef struct game
{
	void	*start;
	void	*finish;
	void	*wall;
	void	*heart;
	void	*mlx;
	void	*win;
	int		wid;
	int		hei;
	int		w_field;
	int		h_field;
	char	**map;
	int		x;
	int		y;
}					t_game;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_visualization(t_game *gm);
void	ft_image(t_game *gm);
void	move_left(t_game *gm);
void	move_right(t_game *gm);
void	move_up(t_game *gm);
void	move_down(t_game *gm);
void	exit_game(void);
int		handle_key_press(int keycode, t_game *gm);
void	init_image(t_game *gm);
void	player_pos(t_game *gm);
void	player_pos(t_game *gm);
void	check_border(t_game *gm);
void	check_rectangular_coins(t_game *gm);
void	check_symbol(t_game *gm);
int		check_coin(t_game *gm);
int		is_path_exists(char **map, int x, int y);
void	check_path(char *str, t_game *gm);

#endif

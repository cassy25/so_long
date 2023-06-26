/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:19:22 by cgeoffra          #+#    #+#             */
/*   Updated: 2023/06/26 13:21:12 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define KEY_A		119
# define KEY_S		115
# define KEY_D		100
# define KEY_W		97

typedef struct s_game
{
	void	*mlx;
	void	*wdw;
	void	*img_collect;
	void	*img_door_c;
	void	*img_door_o;
	void	*img_door_p;
	void	*img_ground;
	void	*img_player;
	void	*img_walls;
	char	**map;
	char	**map2;
	int		height;
	int		width;
	int		player;
	int		collect;
	int		exit;
	int		nbcollect;
	int		player_y;
	int		player_x;
	int		x;
	int		y;
	int		nb_movement;
}		t_game;

char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_free(char **str);
void	save_map(char *file, t_game *game);
void	check_way(t_game *game, int x, int y);
void	pos_player(t_game *game);
void	set_image(t_game *game);
void	mlx(t_game game);
void	put2_image(t_game *game);
int		put_image(t_game *game);
int		setup_map(char *file, t_game *game);
int		check_map(t_game *game);
int		check2_map(t_game *game);
int		check_name(char *n);
int		move_player(int keysym, t_game *game);
int		endgame(t_game *game);
int		close_window(t_game *game);
int		move_player_y(t_game *game, int i);
int		move_player_x(t_game *game, int i);
int		check_charac(t_game *game);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:39:17 by cgeoffra          #+#    #+#             */
/*   Updated: 2023/08/21 21:10:52 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_image(t_game *game)
{
	int	width;
	int	height;

	width = 64;
	height = 64;
	game->img_collect = \
		mlx_xpm_file_to_image(game->mlx, "img/collec.xpm", &width, &height);
	game->img_door_c = \
		mlx_xpm_file_to_image(game->mlx, "img/d_close.xpm", &width, &height);
	game->img_door_o = \
		mlx_xpm_file_to_image(game->mlx, "img/d_open.xpm", &width, &height);
	game->img_door_p = \
		mlx_xpm_file_to_image(game->mlx, "img/d_player.xpm", &width, &height);
	game->img_ground = \
		mlx_xpm_file_to_image(game->mlx, "img/ground.xpm", &width, &height);
	game->img_player = \
		mlx_xpm_file_to_image(game->mlx, "img/player.xpm", &width, &height);
	game->img_walls = \
		mlx_xpm_file_to_image(game->mlx, "img/walls.xpm", &width, &height);
}

int	put_image(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->y)
	{
		x = 0;
		while (x < game->x)
		{
			print_mouvement(game);
			put2_image(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	put2_image(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E' && game->collect != 0)
		mlx_put_image_to_window(game->mlx, game->wdw, \
			game->img_door_c, x * 64, y * 64);
	if (game->map[y][x] == 'F')
		mlx_put_image_to_window(game->mlx, game->wdw, \
			game->img_door_p, x * 64, y * 64);
	if (game->map[y][x] == 'E' && game->collect == 0)
		mlx_put_image_to_window(game->mlx, game->wdw, \
			game->img_door_o, x * 64, y * 64);
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->wdw, \
			game->img_collect, x * 64, y * 64);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->wdw, \
			game->img_walls, x * 64, y * 64);
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->wdw, \
			game->img_ground, x * 64, y * 64);
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->wdw, \
			game->img_player, x * 64, y * 64);
}

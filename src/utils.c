/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:49:52 by cgeoffra          #+#    #+#             */
/*   Updated: 2023/08/21 21:11:19 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	close_window(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_walls);
	mlx_destroy_image(game->mlx, game->img_ground);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_image(game->mlx, game->img_door_c);
	mlx_destroy_image(game->mlx, game->img_door_p);
	mlx_destroy_image(game->mlx, game->img_door_o);
	mlx_destroy_window(game->mlx, game->wdw);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free(game->map);
	ft_free(game->map2);
	exit(0);
	return (0);
}

int	endgame(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->y)
	{
		while (x < game->x)
		{
			if (game->collect == 0)
			{
				if (game->map[game->player_y][game->player_x] == 'F')
				{
					ft_printf("Congrats, You Have Won\n");
					close_window(game);
					return (1);
				}
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

void	print_mouvement(t_game *game)
{
	char	*str;

	str = ft_itoa(game->nb_movement);
	mlx_set_font(game->mlx, game->wdw, "-sony-*-*-*-*-*-50-230-*-*-*-*-*-1");
	mlx_string_put(game->mlx, game->wdw, game->x + 80,
		game->y + 110, 0x0000FF, str);
	free(str);
}

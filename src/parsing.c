/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:05:38 by cgeoffra          #+#    #+#             */
/*   Updated: 2023/06/23 18:41:33 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_charac(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->y)
	{
		x = 0;
		while (x < game->x)
		{
			if (!(game->map[y][x] == 'P' || game->map[y][x] == 'C' \
				|| game->map[y][x] == 'E' || game->map[y][x] == '1' \
				|| game->map[y][x] == '0'))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	check_way(t_game *game, int x, int y)
{
	if (game->map2[y][x] == '1' || game->map2[y][x] == 'X' \
		|| game->nbcollect == 0)
		return ;
	if (game->map2[y][x] == 'C' || game->map2[y][x] == 'E')
	{
		game->map2[y][x] = 'X';
		game->nbcollect -= 1;
	}
	else
		game->map2[y][x] = 'X';
	check_way(game, x + 1, y);
	check_way(game, x, y + 1);
	check_way(game, x - 1, y);
	check_way(game, x, y - 1);
}

void	pos_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				check_way(game, x, y);
				return ;
			}
			x++;
		}
		y++;
	}
}

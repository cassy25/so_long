/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:53:25 by cgeoffra          #+#    #+#             */
/*   Updated: 2023/06/26 13:17:48 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		close_window(game);
	if (keysym == KEY_A)
		game->nb_movement += move_player_y(game, -1);
	if (keysym == KEY_S)
		game->nb_movement += move_player_y(game, 1);
	if (keysym == KEY_D)
		game->nb_movement += move_player_x(game, 1);
	if (keysym == KEY_W)
		game->nb_movement += move_player_x(game, -1);
	endgame(game);
	return (0);
}

int	move_player_y(t_game *game, int i)
{
	if (game->map[game->player_y + i][game->player_x] != '1')
	{
		if (game->map[game->player_y + i][game->player_x] == 'C')
			game->collect -= 1;
		if (game->map[game->player_y][game->player_x] == 'F')
			game->map[game->player_y][game->player_x] = 'E';
		else
			game->map[game->player_y][game->player_x] = '0';
		game->player_y += i;
		if (game->map[game->player_y][game->player_x] == 'E')
			game->map[game->player_y][game->player_x] = 'F';
		else
			game->map[game->player_y][game->player_x] = 'P';
		ft_printf("You Made : %i Movements\n", game->nb_movement + 1);
		return (1);
	}
	return (0);
}

int	move_player_x(t_game *game, int i)
{
	if (game->map[game->player_y][game->player_x + i] != '1')
	{
		if (game->map[game->player_y][game->player_x + i] == 'C')
			game->collect -= 1;
		if (game->map[game->player_y][game->player_x] == 'F')
			game->map[game->player_y][game->player_x] = 'E';
		else
			game->map[game->player_y][game->player_x] = '0';
		game->player_x += i;
		if (game->map[game->player_y][game->player_x] == 'E')
			game->map[game->player_y][game->player_x] = 'F';
		else
			game->map[game->player_y][game->player_x] = 'P';
		ft_printf("You Made : %i Movements\n", game->nb_movement + 1);
		return (1);
	}
	return (0);
}

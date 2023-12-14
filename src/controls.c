/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:53:25 by cgeoffra          #+#    #+#             */
/*   Updated: 2023/08/16 19:05:23 by cgeoffra         ###   ########.fr       */
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
		return (1);
	}
	return (0);
}

char	*ft_strrev(char *str, int neg, int n, int len)
{
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = (neg * (n % 10)) + 48;
		n /= 10;
		len--;
	}
	if (neg == -1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		nbr;
	int		neg;
	int		len;
	char	*str;

	nbr = n;
	neg = 1;
	len = 0;
	if (n < 0)
	{
		len++;
		neg = -1;
	}
	while (nbr >= 10 || nbr <= -10)
	{
		nbr /= 10;
		len++;
	}
	len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str = ft_strrev(str, neg, n, len);
	return (str);
}

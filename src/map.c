/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:37:54 by cgeoffra          #+#    #+#             */
/*   Updated: 2023/09/26 11:59:00 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	setup_map(char *file, t_game *game)
{
	int		fd;
	char	*str;

	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	if (str == NULL)
		return (1);
	game->x = ft_strlen(str) - 1;
	game->y = 0;
	while (str != NULL)
	{
		game->y++;
		if ((int)ft_strlen(str) - 1 != game->x)
		{
			close(fd);
			free(str);
			return (1);
		}
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}
// Penser a faire verif du x si return(1) et tous les cas d'erreur
// Enregistrer la map

void	save_map(char *file, t_game *game)
{
	int		fd;
	int		i;

	game->nb_movement = 0;
	i = 0;
	fd = open(file, O_RDONLY);
	game->map = malloc(sizeof(char **) * (game->y + 1));
	game->map2 = malloc(sizeof(char **) * (game->y + 1));
	game->map[game->y] = 0;
	game->map2[game->y] = 0;
	while (i < game->y)
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	i = 0;
	fd = open(file, O_RDONLY);
	while (i < game->y)
	{
		game->map2[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

// Verifier les objets collectables, sortie et player

int	check_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->player = 0;
	game->collect = 0;
	game->exit = 0;
	while (y < game->y)
	{
		x = 0;
		while (x < game->x)
		{
			if (game->map[y][x] == 'E')
				game->exit++;
			if (game->map[y][x] == 'C')
				game->collect++;
			if (game->map[y][x] == 'P')
				game->player++;
			x++;
		}
		y++;
	}
	if (game->exit != 1 || game->collect <= 0 || game->player != 1)
		return (1);
	return (0);
}

// Verifier si c'est entoure de murs

int	check2_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->y)
	{
		if (y == 0 || y == game->y - 1)
		{
			x = 0;
			while (x < (game->x))
			{
				if (game->map[y][x] != '1')
					return (1);
				x++;
			}
		}
		else
		{
			if (game->map[y][0] != '1' || game->map[y][game->x - 1] != '1')
				return (1);
		}
		y++;
	}
	return (0);
}
// Verifier que argv[1] est un .ber

int	check_name(char *n)
{
	int		i;
	int		j;
	char	*str;

	j = (ft_strlen(n) - 1);
	str = "reb.";
	i = 0;
	while (i <= 3)
	{
		if (str[i++] != n[j--])
			return (1);
	}
	i = open(n, O_RDONLY);
	if (i == -1)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:44:47 by cgeoffra          #+#    #+#             */
/*   Updated: 2023/08/16 18:33:00 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(t_game *game, char *s)
{
	ft_free(game->map);
	ft_free(game->map2);
	ft_printf("%s", s);
	return (1);
}

void	mlx(t_game game)
{
	game.mlx = mlx_init();
	game.wdw = mlx_new_window(game.mlx, game.x * 64, game.y * 64, "Let's Game");
	set_image(&game);
	mlx_loop_hook(game.mlx, put_image, &game);
	mlx_hook(game.wdw, 2, 1, move_player, &game);
	mlx_hook(game.wdw, 17, 1, close_window, &game);
	mlx_loop(game.mlx);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Error\nPlease put a map"));
	if (check_name(argv[1]) == 1)
		return (ft_printf("Error\nMap name is invalid"));
	if (setup_map(argv[1], &game) == 1)
		return (ft_printf("Error\nMap is not rectangular or valid"));
	save_map(argv[1], &game);
	if (check_map(&game) == 1)
		return (ft_error(&game, "Error\nNot enought or more of P, C or E"));
	game.nbcollect = game.collect + 1;
	if (check2_map(&game) == 1)
		return (ft_error(&game, "Error\nMap is not surrounded by walls"));
	if (check_charac(&game) == 1)
		return (ft_error(&game, "Error\nOther characters in your map"));
	pos_player(&game);
	if (game.nbcollect != 0)
		return (ft_error(&game, "Error\nE or C is not reachable"));
	mlx(game);
	return (0);
}

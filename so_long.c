/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 21:58:51 by byan              #+#    #+#             */
/*   Updated: 2022/07/24 01:37:25 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game, char *map)
{
	game->mlx = mlx_init();
	game->img = img_init(game->mlx);
	map_read(map, game);
	map_check_start(game);
	game->window = mlx_new_window
		(game->mlx, game->width * 32, game->height * 32, "so_long");
	img_setting(game);
}

int	clear_game(t_game *game)
{
	game->walk++;
	printf("%s %d %s\n", "Clear : You moved", game->walk, "times");
	exit(0);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
}

int	key_press(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit_game(game);
	if (key_code == KEY_W)
		move_w(game);
	if (key_code == KEY_A)
		move_a(game);
	if (key_code == KEY_S)
		move_s(game);
	if (key_code == KEY_D)
		move_d(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		print_err("Missing map");
	game = malloc(sizeof(t_game));
	game_init(game, argv[1]);
	mlx_hook(game->window, ON_KEYDOWN, 0, &key_press, game);
	mlx_hook(game->window, ON_DESTROY, 0, &exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}

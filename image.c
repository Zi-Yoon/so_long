/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 23:31:25 by byan              #+#    #+#             */
/*   Updated: 2022/07/11 16:57:29 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	img_init(void *mlx)
{
	t_img	img;
	int		width;
	int		height;

	img.land = mlx_xpm_file_to_image
		(mlx, "./images/land.xpm", &width, &height);
	img.wall = mlx_xpm_file_to_image
		(mlx, "./images/wall.xpm", &width, &height);
	img.player = mlx_xpm_file_to_image
		(mlx, "./images/player.xpm", &width, &height);
	img.key = mlx_xpm_file_to_image
		(mlx, "./images/coffee.xpm", &width, &height);
	img.close = mlx_xpm_file_to_image
		(mlx, "./images/locked.xpm", &width, &height);
	img.open = mlx_xpm_file_to_image
		(mlx, "./images/mac.xpm", &width, &height);
	return (img);
}

void	img_put(t_game *g, int w, int h)
{
	if (g->str_line[h * g->width + w] == '1')
		mlx_put_image_to_window
		(g->mlx, g->window, g->img.wall, w * 32, h * 32);
	else if (g->str_line[h * g->width + w] == 'C')
		mlx_put_image_to_window
		(g->mlx, g->window, g->img.key, w * 32, h * 32);
	else if (g->str_line[h * g->width + w] == 'P')
		mlx_put_image_to_window
		(g->mlx, g->window, g->img.player, w * 32, h * 32);
	else if (g->str_line[h * g->width + w] == 'E' && g->all_col == g->col_cnt)
		mlx_put_image_to_window
		(g->mlx, g->window, g->img.open, w * 32, h * 32);
	else if (g->str_line[h * g->width + w] == 'E')
		mlx_put_image_to_window
		(g->mlx, g->window, g->img.close, w * 32, h * 32);
	else
		mlx_put_image_to_window
		(g->mlx, g->window, g->img.land, w * 32, h * 32);
}

void	img_setting(t_game *game)
{
	int		height;
	int		width;

	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			img_put(game, width, height);
			width++;
		}
		height++;
	}
}

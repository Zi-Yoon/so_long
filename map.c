/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:33:40 by byan              #+#    #+#             */
/*   Updated: 2022/08/08 13:14:25 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		print_err("File open fail\n");
	line = get_next_line(fd);
	game->height = 0;
	game->walk = 0;
	game->width = ft_strlen(line) - 1;
	game->str_line = ft_strdup_no_nl(line);
	free(line);
	while (line)
	{
		game->height++;
		line = get_next_line(fd);
		if (line)
			game->str_line = ft_strjoin_no_nl(game->str_line, line);
	}
	close(fd);
}

void	map_check_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < ft_strlen(game->str_line))
	{
		if (i < game->width)
		{
			if (game->str_line[i] != '1')
				print_err("Map : No walls at edge\n");
		}
		else if (i % game->width == 0 || i % game->width == game->width - 1)
		{
			if (game->str_line[i] != '1')
				print_err("Map : No walls at edge\n");
		}
		else if (i > ft_strlen(game->str_line) - game->width)
		{
			if (game->str_line[i] != '1')
				print_err("Map : No walls at edge\n");
		}
		i++;
	}
}

void	map_check_elements(t_game *game)
{
	int	i;
	int	e_cnt;
	int	p_cnt;

	i = 0;
	e_cnt = 0;
	p_cnt = 0;
	game->all_col = 0;
	game->col_cnt = 0;
	while (i++ < ft_strlen(game->str_line))
	{
		if (game->str_line[i] == 'E')
			e_cnt++;
		else if (game->str_line[i] == 'P')
			p_cnt++;
		else if (game->str_line[i] == 'C')
			game->all_col++;
	}
	if (e_cnt != 1)
		print_err("Map : Exit error\n");
	if (game->all_col == 0)
		print_err("Map : No coffee to collect\n");
	if (p_cnt != 1)
		print_err("Map : Starting position error\n");
}

void	map_check_wrong(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(game->str_line))
	{
		if (game->str_line[i] != 'E' && game->str_line[i] != 'P'
			&& game->str_line[i] != 'C' && game->str_line[i] != '0'
			&& game->str_line[i] != '1' && game->str_line[i] != '\n'
			&& game->str_line[i] != '\0')
			print_err("Map : Wrong element\n");
	}
}

void	map_check_start(t_game *game)
{
	if (game->height * game->width != ft_strlen(game->str_line))
		print_err("Map : Not rectangular.\n");
	map_check_wall(game);
	map_check_wrong(game);
	map_check_elements(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:00:14 by byan              #+#    #+#             */
/*   Updated: 2022/07/11 17:33:10 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"

# define ON_KEYDOWN	2
# define ON_KEYUP	3
# define ON_DESTROY	17
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

typedef struct s_img
{
	void	*player;
	void	*key;
	void	*land;
	void	*close;
	void	*open;
	void	*wall;
}				t_img;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_img	img;
	int		width;
	int		height;
	char	*str_line;
	int		all_col;
	int		col_cnt;
	int		walk;
}				t_game;

void	print_err(char *message);
char	*ft_strdup_no_nl(char *s);
int		ft_strlcpy_no_nl(char *dst, char *src, int len);
char	*ft_strjoin_no_nl(char *s1, char *s2);
t_img	img_init(void *mlx);
void	img_put(t_game *g, int w, int h);
void	img_setting(t_game *game);
void	map_read(char *filename, t_game *game);
void	map_check_wall(t_game *game);
void	map_check_elements(t_game *game);
void	map_check_start(t_game *game);
void	move_w(t_game *g);
void	move_a(t_game *g);
void	move_s(t_game *g);
void	move_d(t_game *g);
void	game_init(t_game *g, char *map);
int		clear_game(t_game *game);
int		exit_game(t_game *game);
int		key_press(int key_code, t_game *game);
int		main(int ac, char *av[]);

#endif
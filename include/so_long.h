/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:52:32 by damarry           #+#    #+#             */
/*   Updated: 2022/04/21 20:14:43 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <string.h>

// sprites
# define WALL		"sprites/wall.xpm"
# define FLOOR		"sprites/pol.xpm"
# define PLAYER1	"sprites/player_right_0.xpm"
# define PLAYER2	"sprites/player_left_0.xpm"
# define EXIT1		"sprites/doorclosed.xpm"
# define EXIT2		"sprites/dooropened.xpm"
# define COIN1		"sprites/coin_1.xpm"
# define COIN2		"sprites/coin_0.xpm"
# define ENEMY1		"sprites/ghost_0.xpm"
# define ENEMY2		"sprites/ghost_3.xpm"

// keys
# define ESC	53
# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2

// size sprite X Y
# define SPRITE_X	64
# define SPRITE_Y	64
# define SPRITE		128

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*player1;
	void	*player2;
	void	*exit1;
	void	*exit2;
	void	*coin;
	void	*coin1;
	void	*coin2;
	void	*fire;
	void	*fire1;
	void	*fire2;
}			t_img;

typedef struct s_map
{
	void		*mlx;
	void		*win;
	char		**map;
	int			length;
	int			width;
	int			coin;
	int			steps;
	int			enemy;
	t_vector	play_coord;
	t_vector	enem_coord[10];
	t_img		img;
}				t_map;

// sl_parser_check_bonus.c
void	check_map_whole(t_map *map, char **av);
void	check_map_line(t_map *map);
void	check_map_arg(t_map *map, int i, int j);
void	init_player(t_map *map, int i, int j, int *player);
void	check_map_arg2(t_map *map, int i, int j);
void	check_map_border(t_map *map, int i, int j);

// sl_parser_init_bonus.c
char	*get_line(char **av);
t_map	*init_map(char *line);
void	init_sprites(t_map *map);
void	dop_usl(t_map *map);
// void	drow_image(t_map *map);
void	init_enemy(t_map *map);

// sl_parser_error_bonus.c
void	ft_error(char *str);
void	error_arg(char *str);
void	check_argc(int ac, char **av);
void	error_fd(void);
void	free_arr_map(t_map *map);

// sl_move_player_bonus.c
int		drow_map(t_map *map);
int		keys(int key, t_map *map);
int		end_game(void);
void	animation(t_map *map);

// sl_move_up_down_bonus.c
void	move_player_up(t_map *map);
void	move_player_down(t_map *map);
void	move_up(t_map *map);
void	move_down(t_map *map);

// sl_move_left_right_bonus.c
void	steps(t_map *map);
void	move_player_left(t_map *map);
void	move_player_right(t_map *map);
void	move_left(t_map *map);
void	move_right(t_map *map);

// sl_move_enemy.c
void	enemy_move(t_map *map);
void	enemy_move_right(t_map *map);
void	enemy_move_left(t_map *map);
void	enemy_move_down(t_map *map);
void	enemy_move_up(t_map *map);

#endif

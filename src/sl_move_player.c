/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:51:57 by damarry           #+#    #+#             */
/*   Updated: 2022/04/21 19:42:45 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	drow_map2(t_map *map, int i, int j)
{
	if (map->map[i][j] == '1')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.wall, j * SPRITE, i * SPRITE);
	else if (map->map[i][j] == '0')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.floor, j * SPRITE, i * SPRITE);
	else if (map->map[i][j] == 'P')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.player, j * SPRITE, i * SPRITE);
	else if (map->map[i][j] == 'E')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.exit1, j * SPRITE, i * SPRITE);
	else if (map->map[i][j] == 'C')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.coin1, j * SPRITE, i * SPRITE);
}

int	drow_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
			drow_map2(map, i, j);
	}
	return (0);
}

int	keys(int key, t_map *map)
{
	if (key == UP)
		move_player_up(map);
	else if (key == DOWN)
		move_player_down(map);
	else if (key == LEFT)
		move_player_left(map);
	else if (key == RIGHT)
		move_player_right(map);
	else if (key == ESC)
		end_game();
	drow_map(map);
	return (0);
}

int	end_game(void)
{
	printf("Игра окончена.\n");
	exit(0);
	return (0);
}

void	steps(t_map *map)
{
	map->steps++;
	printf("\033[34mSteps: %d\n\e[0m", map->steps);
}

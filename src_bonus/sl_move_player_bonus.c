/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:50:39 by damarry           #+#    #+#             */
/*   Updated: 2022/04/21 19:37:04 by damarry          ###   ########.fr       */
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
		map->img.coin, j * SPRITE, i * SPRITE);
	else if (map->map[i][j] == 'X')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.fire, j * SPRITE, i * SPRITE);
}

void	animation(t_map *map)
{
	enemy_move(map);
	if (map->img.coin == map->img.coin1)
		map->img.coin = map->img.coin2;
	else if (map->img.coin == map->img.coin2)
		map->img.coin = map->img.coin1;
	if (map->img.fire == map->img.fire1)
		map->img.fire = map->img.fire2;
	else if (map->img.fire == map->img.fire2)
		map->img.fire = map->img.fire1;
	if (map->coin == 0)
		map->img.exit1 = map->img.exit2;
}

int	drow_map(t_map *map)
{
	static int		k;
	int				i;
	int				j;
	char			*count_step;

	k++;
	if (k > 30)
	{
		animation(map);
		k = 0;
	}
	count_step = ft_itoa(map->steps);
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
			drow_map2(map, i, j);
	}
	mlx_string_put(map->mlx, map->win, 10, 10, 759, "Steps:");
	mlx_string_put(map->mlx, map->win, 75, 10, 759, count_step);
	free(count_step);
	return (0);
}

int	keys(int key, t_map *map)
{
	if (key == UP || key == 126)
		move_player_up(map);
	else if (key == DOWN | key == 125)
		move_player_down(map);
	else if (key == LEFT | key == 123)
		move_player_left(map);
	else if (key == RIGHT | key == 124)
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

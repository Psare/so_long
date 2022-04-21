/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_left_right_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:50:46 by damarry           #+#    #+#             */
/*   Updated: 2022/04/21 19:42:02 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	steps(t_map *map)
{
	map->steps++;
	printf("\033[34mSteps: %d\n\e[0m", map->steps);
}

void	move_left(t_map *map)
{
	map->map[map->play_coord.y][map->play_coord.x - 1] = 'P';
	map->map[map->play_coord.y][map->play_coord.x] = '0';
	map->play_coord.x--;
	steps(map);
}

void	move_right(t_map *map)
{
	map->map[map->play_coord.y][map->play_coord.x + 1] = 'P';
	map->map[map->play_coord.y][map->play_coord.x] = '0';
	map->play_coord.x++;
	steps(map);
}

void	move_player_left(t_map *map)
{
	map->img.player = map->img.player2;
	if (map->map[map->play_coord.y][map->play_coord.x - 1] == '0')
		move_left(map);
	else if (map->map[map->play_coord.y][map->play_coord.x - 1] == 'C')
	{
		move_left(map);
		map->coin--;
	}
	else if (map->map[map->play_coord.y][map->play_coord.x - 1] == 'E' &&
			map->coin == 0)
		end_game();
	else if (map->map[map->play_coord.y][map->play_coord.x - 1] == 'X')
		end_game();
}

void	move_player_right(t_map *map)
{
	map->img.player = map->img.player1;
	if (map->map[map->play_coord.y][map->play_coord.x + 1] == '0')
		move_right(map);
	else if (map->map[map->play_coord.y][map->play_coord.x + 1] == 'C')
	{
		move_right(map);
		map->coin--;
	}
	else if (map->map[map->play_coord.y][map->play_coord.x + 1] == 'E' &&
		map->coin == 0)
		end_game();
	else if (map->map[map->play_coord.y][map->play_coord.x + 1] == 'X')
		end_game();
}

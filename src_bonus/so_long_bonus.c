/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:49:51 by damarry           #+#    #+#             */
/*   Updated: 2022/04/21 19:30:17 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game(t_map *map)
{
	mlx_hook(map->win, 2, 0, keys, map);
	mlx_hook(map->win, 17, 0, end_game, map);
	mlx_loop_hook(map->mlx, drow_map, map);
	mlx_loop(map->mlx);
}

t_map	*parsing(int argc, char **argv)
{
	t_map	*map;
	char	*line;

	check_argc(argc, argv);
	line = get_line(argv);
	map = init_map(line);
	init_sprites(map);
	check_map_whole(map, argv);
	check_map_line(map);
	check_map_arg2(map, -1, -1);
	check_map_border(map, 0, 0);
	init_enemy(map);
	return (map);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = parsing(argc, argv);
	game(map);
	free_arr_map(map);
	return (0);
}

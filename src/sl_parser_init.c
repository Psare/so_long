/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parser_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:51:23 by damarry           #+#    #+#             */
/*   Updated: 2022/04/21 18:21:49 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_line(char **av)
{
	int		fd;
	char	*new_line;
	char	*line;
	char	*tmp;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_fd();
	new_line = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = new_line;
		new_line = ft_gnl_strjoin(new_line, line);
		free(tmp);
		free(line);
	}
	close(fd);
	return (new_line);
}

t_map	*init_map(char *line)
{
	t_map	*map;
	int		i;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = ft_split(line, '\n');
	i = 0;
	while (map->map[i])
		i++;
	map->length = ft_strlen(map->map[0]);
	map->width = i;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->length * SPRITE, \
							map->width * SPRITE, "so_long");
	map->coin = 0;
	map->steps = 0;
	free(line);
	return (map);
}

void	init_sprites(t_map *map)
{
	int	x;
	int	y;

	x = SPRITE;
	y = SPRITE;
	map->img.wall = mlx_xpm_file_to_image(map->mlx, WALL, &x, &y);
	map->img.floor = mlx_xpm_file_to_image(map->mlx, FLOOR, &x, &y);
	map->img.player = mlx_xpm_file_to_image(map->mlx, PLAYER1, &x, &y);
	map->img.exit1 = mlx_xpm_file_to_image(map->mlx, EXIT1, &x, &y);
	map->img.coin1 = mlx_xpm_file_to_image(map->mlx, COIN1, &x, &y);
	map->img.coin2 = mlx_xpm_file_to_image(map->mlx, COIN2, &x, &y);
	if (!map->img.wall || !map->img.floor || !map->img.player
		|| !map->img.exit1 || !map->img.coin1)
	{
		printf("Не удалось открыть файл с картинкой.\n");
		exit(1);
	}
	map->img.coin = map->img.coin1;
}

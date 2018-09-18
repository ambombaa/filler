/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 18:07:54 by ambombaa          #+#    #+#             */
/*   Updated: 2018/08/07 11:30:23 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		vertical_check(t_map *map, int col, char c)
{
	int		row;

	row = 0;
	while (row < map->map_y)
	{
		if (map->grid[row][col] == c || map->grid[row][col] == ft_tolower(c))
			return (1);
		row++;
	}
	return (0);
}

static int		horizontal_check(t_map *map, int row, char c)
{
	int		col;

	col = 0;
	while (col < map->map_x)
	{
		if (map->grid[row][col] == c || map->grid[row][col] == ft_tolower(c))
			return (1);
		col++;
	}
	return (0);
}

static int		enemy_in_vicinity(t_map *map)
{
	int		y;
	int		x;

	y = map->map_y - 1;
	while (y >= 0)
	{
		x = map->map_x - 1;
		while (x >= 0)
		{
			if (map->grid[y][x] == map->me)
			{
				return ((horizontal_check(map, y, map->enemy) == 1) ||
						horizontal_check(map, y, map->me));
			}
			x--;
		}
		y--;
	}
	return (0);
}

static void		check_top_bottom_reached(t_map *map)
{
	if (horizontal_check(map, 0, map->me) ||
			horizontal_check(map, map->map_y - 1, map->me))
		map->block_enemy = 1;
	else
		map->block_enemy = 0;
}

int				play_game(t_map *map, t_piece *piece)
{
	if (map->end == 1)
	{
		display_move(0, 0);
		return (0);
	}
	else
	{
		update_data(map, piece);
		check_top_bottom_reached(map);
		if (vertical_check(map, map->map_x - 1, map->me) == 0 &&
				vertical_check(map, 0, map->me) == 0 &&
				enemy_in_vicinity(map) == 0)
			move_downwards(map, piece);
		if (enemy_in_vicinity(map) == 1 && map->block_enemy == 0)
			move_downwards(map, piece);
		else
			move_upwards(map, piece);
		return (1);
	}
}

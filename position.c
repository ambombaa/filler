/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 18:05:26 by ambombaa          #+#    #+#             */
/*   Updated: 2018/08/13 10:33:45 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	bottom_right(t_map *map, t_piece *piece, int y, int x)
{
	int		i;
	int		j;

	i = piece->piece_y - 1;
	while (i >= 0)
	{
		j = piece->piece_x - 1;
		while (j >= 0)
		{
			if (is_valid_move(map, piece, x - j, y - i))
			{
				display_move(y - i, x - j);
				return (1);
			}
			j--;
		}
		i--;
	}
	return (0);
}

static int	top_left(t_map *map, t_piece *piece, int y, int x)
{
	int		i;
	int		j;

	i = 0;
	while (i < piece->piece_y)
	{
		j = 0;
		while (j < piece->piece_x)
		{
			if (is_valid_move(map, piece, x - j, y - i))
			{
				display_move(y - i, x - j);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void		move_downwards(t_map *map, t_piece *piece)
{
	int		y;
	int		x;

	y = 0;
	while (y < map->map_y)
	{
		x = 0;
		while (x < map->map_x)
		{
			if (map->grid[y][x] == map->me)
				if (bottom_right(map, piece, y, x) == 1)
					return ;
			x++;
		}
		y++;
	}
	map->end = 1;
}

void		move_upwards(t_map *map, t_piece *piece)
{
	int		y;
	int		x;

	y = map->map_y - 1;
	while (y > 0)
	{
		x = map->map_x - 1;
		while (x > 0)
		{
			if (map->grid[y][x] == map->me)
				if (top_left(map, piece, y, x) == 1)
					return ;
			x--;
		}
		y--;
	}
	map->end = 1;
}

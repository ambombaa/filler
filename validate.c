/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 18:01:09 by ambombaa          #+#    #+#             */
/*   Updated: 2018/08/07 09:54:47 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_boundary(t_map *map, t_piece *piece, int x, int y)
{
	if (x < 0 || x >= map->map_x || x + piece->piece_x > map->map_x)
		return (0);
	if (y < 0 || y >= map->map_y || y + piece->piece_y > map->map_y)
		return (0);
	return (1);
}

int			is_valid_move(t_map *map, t_piece *piece, int x, int y)
{
	int		i;
	int		j;
	int		t_x;
	int		t_y;
	int		count;

	i = -1;
	count = 0;
	t_y = y;
	while (check_boundary(map, piece, x, y) && ++i < piece->piece_y)
	{
		j = -1;
		t_x = x;
		while (++j < piece->piece_x)
		{
			if (piece->grid[i][j] == '*' && map->grid[t_y][t_x] == map->me)
				count++;
			if (piece->grid[i][j] == '*' && map->grid[t_y][t_x] == map->enemy)
				return (0);
			t_x++;
		}
		t_y++;
	}
	return (count == 1);
}

void		display_move(int x, int y)
{
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
}

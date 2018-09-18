/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:53:10 by ambombaa          #+#    #+#             */
/*   Updated: 2018/08/06 12:52:47 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		get_grid(t_map *map, t_piece *piece, int choice)
{
	char	*line;
	char	**split;
	int		index;

	line = NULL;
	index = 0;
	alloc_grid_mem(map, piece, choice);
	if (choice == 1)
	{
		get_next_line(0, &line);
		while (index < map->map_y && get_next_line(0, &line) > 0)
		{
			split = ft_strsplit(line, ' ');
			map->grid[index] = ft_strdup(split[1]);
			index++;
		}
	}
	else
	{
		while (index < piece->piece_y && get_next_line(0, &line) > 0)
		{
			piece->grid[index] = ft_strdup(line);
			index++;
		}
	}
}

void			update_data(t_map *map, t_piece *piece)
{
	get_board_dimensions(map);
	get_grid(map, piece, 1);
	get_piece_dimensions(piece);
	get_grid(map, piece, 0);
}

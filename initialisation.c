/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:50:43 by ambombaa          #+#    #+#             */
/*   Updated: 2018/08/06 12:49:45 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			get_player_num(t_map *map)
{
	char	*line;

	line = NULL;
	get_next_line(0, &line);
	map->nbr = ft_atoi(&line[10]);
	if (map->nbr == 1)
	{
		map->me = 'O';
		map->enemy = 'X';
	}
	else
	{
		map->me = 'X';
		map->enemy = 'O';
	}
}

void			get_board_dimensions(t_map *map)
{
	char *line;
	char **array;

	line = NULL;
	get_next_line(0, &line);
	array = ft_strsplit(line, ' ');
	map->map_y = ft_atoi(array[1]);
	map->map_x = ft_atoi(array[2]);
}

void			get_piece_dimensions(t_piece *piece)
{
	char	*line;
	char	**array;

	line = NULL;
	get_next_line(0, &line);
	array = ft_strsplit(line, ' ');
	piece->piece_y = ft_atoi(array[1]);
	piece->piece_x = ft_atoi(array[2]);
}

static void		clear_grid(t_map *map, t_piece *piece, int choice)
{
	int			index;

	index = 0;
	if (choice == 1)
	{
		while (map->grid && map->grid[index] != NULL)
		{
			free(map->grid[index]);
			map->grid[index] = NULL;
			index++;
		}
		free(map->grid);
		map->grid = NULL;
	}
	else
	{
		while (piece->grid && piece->grid[index] != NULL)
		{
			free(piece->grid[index]);
			piece->grid[index] = NULL;
			index++;
		}
		free(piece->grid);
		piece->grid = NULL;
	}
}

void			alloc_grid_mem(t_map *map, t_piece *piece, int choice)
{
	if (choice == 1)
	{
		clear_grid(map, piece, 1);
		map->grid = (char**)malloc(sizeof(char*) * (map->map_y + 1));
		map->grid[map->map_y] = NULL;
	}
	else
	{
		clear_grid(map, piece, 0);
		piece->grid = (char**)malloc(sizeof(char*) * (piece->piece_y + 1));
		piece->grid[piece->piece_y] = NULL;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:18:53 by ambombaa          #+#    #+#             */
/*   Updated: 2018/08/07 09:34:59 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_map
{
	int			nbr;
	int			map_y;
	int			map_x;
	int			block_enemy;
	int			end;
	char		me;
	char		enemy;
	char		**grid;
}				t_map;

typedef struct	s_piece
{
	int			piece_y;
	int			piece_x;
	int			x;
	int			y;
	char		**grid;
}				t_piece;

void			move_downwards(t_map *info, t_piece *piece);
void			move_upwards(t_map *info, t_piece *piece);
void			get_board_dimensions(t_map *info);
void			get_piece_dimensions(t_piece *piece);
void			update_data(t_map *info, t_piece *piece);
void			obtain_map(t_map *info, t_piece *piece);
int				play_game(t_map *info, t_piece *piece);
int				check_piece_size(t_map *info, t_piece *piece, int x, int y);
int				get_next_line(int const fd, char **line);
void			get_player_num(t_map *info);
void			alloc_grid_mem(t_map *info, t_piece *piece, int choice);
int				is_valid_move(t_map *info, t_piece *piece, int x, int y);
void			display_move(int x, int y);

#endif

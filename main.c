/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:15:41 by ambombaa          #+#    #+#             */
/*   Updated: 2018/08/07 11:30:33 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				main(void)
{
	t_map	map;
	t_piece	piece;

	map = (t_map){0, 0, 0, 0, 0, 0, 0, NULL};
	piece = (t_piece){0, 0, 0, 0, NULL};
	get_player_num(&map);
	while (play_game(&map, &piece) != 0)
		;
}

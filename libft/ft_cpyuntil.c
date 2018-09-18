/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpyuntil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:23:08 by ambombaa          #+#    #+#             */
/*   Updated: 2018/08/04 14:23:11 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cpyuntil(char **dst, char *src, char c)
{
	int		i;
	int		poz;
	int		counter;

	i = -1;
	counter = 0;
	while (src[++i])
		if (src[i] == c)
			break ;
	poz = i;
	if (!(*dst = ft_strnew(i)))
		return (0);
	while (src[counter] && counter < i)
	{
		if (!(*dst = ft_strjoinchr(*dst, src[counter])))
			return (0);
		counter++;
	}
	return (poz);
}

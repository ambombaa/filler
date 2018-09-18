/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:30:26 by ambombaa          #+#    #+#             */
/*   Updated: 2018/08/04 14:30:29 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp;
	char	*temp2;
	int		i;

	temp = (char *)dest;
	temp2 = (char *)src;
	if (temp > temp2)
	{
		i = n - 1;
		while (i >= 0)
		{
			temp[i] = temp2[i];
			i--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return ((void *)dest);
}

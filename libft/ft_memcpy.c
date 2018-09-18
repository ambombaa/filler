/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:29:47 by ambombaa          #+#    #+#             */
/*   Updated: 2018/08/05 09:14:32 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*temp;
	char	*temp2;

	i = 0;
	if (n == 0 || dest == src)
		return (dest);
	temp = (char *)dest;
	temp2 = (char *)src;
	while (i < n)
	{
		temp[i] = temp2[i];
		i++;
	}
	dest = (void *)temp;
	return (dest);
}

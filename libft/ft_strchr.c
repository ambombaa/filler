/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:33:00 by ambombaa          #+#    #+#             */
/*   Updated: 2018/08/04 14:33:03 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *haystack, int c)
{
	int		i;
	char	*temp;
	int		len;

	i = 0;
	len = ft_strlen(haystack) + 1;
	while (len)
	{
		if (haystack[i] == (char)c)
		{
			temp = (char *)(haystack + i);
			return ((char *)temp);
		}
		len--;
		i++;
	}
	return (NULL);
}

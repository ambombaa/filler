/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:35:51 by ambombaa          #+#    #+#             */
/*   Updated: 2018/08/07 11:25:34 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinchr(char const *s, char c)
{
	char	*new_str;
	size_t	i;
	size_t	s_len;

	if (!s || !c)
		return (NULL);
	s_len = ft_strlen(s);
	new_str = ft_strnew(s_len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < s_len)
		*(new_str + i) = *(s + i);
	*(new_str + i) = c;
	return (new_str);
}

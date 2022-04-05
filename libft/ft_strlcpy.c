/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:44:19 by asibille          #+#    #+#             */
/*   Updated: 2022/01/13 12:42:37 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] > 0)
		++i;
	if (dstsize == 0)
		return (i);
	while (*src && ((dstsize - 1) > 0))
	{
		*dst = *src;
		++dst;
		++src;
		--dstsize;
	}
	*dst = 0;
	return (i);
}

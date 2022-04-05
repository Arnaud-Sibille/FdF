/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:41:00 by asibille          #+#    #+#             */
/*   Updated: 2022/01/05 17:14:14 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst1;
	unsigned const char	*src1;
	size_t				i;

	dst1 = dst;
	src1 = src;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len > 0)
		{
			--len;
			dst1[len] = src1[len];
		}
		return (dst);
	}
	else
	{
		i = -1;
		while (++i < len)
			dst1[i] = src1[i];
		return (dst);
	}
}

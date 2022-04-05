/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:10:45 by asibille          #+#    #+#             */
/*   Updated: 2022/01/13 12:39:34 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst2;
	unsigned const char	*src2;

	dst2 = dst;
	src2 = src;
	if (!dst && !src)
		return (NULL);
	while (n > 0)
	{
		*dst2 = *src2;
		++dst2;
		++src2;
		n--;
	}
	return (dst);
}

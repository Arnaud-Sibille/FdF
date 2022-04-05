/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:29:44 by asibille          #+#    #+#             */
/*   Updated: 2022/01/05 16:36:38 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1bis;
	const unsigned char	*s2bis;

	s1bis = s1;
	s2bis = s2;
	while (n > 0)
	{
		if (*s1bis != *s2bis)
			return (*s1bis - *s2bis);
		++s1bis;
		++s2bis;
		--n;
	}
	return (0);
}

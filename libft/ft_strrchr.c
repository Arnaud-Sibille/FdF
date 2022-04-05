/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:17:58 by asibille          #+#    #+#             */
/*   Updated: 2022/01/13 12:22:18 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	c2;

	c2 = (char) c;
	len = ft_strlen(s);
	s = &s[len];
	++len;
	while (len-- > 0)
	{
		if (*s == c2)
			return ((char *) s);
		--s;
	}
	return (0);
}

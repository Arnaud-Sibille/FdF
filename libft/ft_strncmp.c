/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:50:53 by asibille          #+#    #+#             */
/*   Updated: 2022/01/12 16:38:36 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1bis;
	unsigned char	*s2bis;

	s1bis = (unsigned char *) s1;
	s2bis = (unsigned char *) s2;
	while (*s1bis && *s2bis && n > 0)
	{
		if (*s1bis != *s2bis)
			return (*s1bis - *s2bis);
		++s1bis;
		++s2bis;
		--n;
	}
	if (n == 0)
		return (0);
	return (*s1bis - *s2bis);
}

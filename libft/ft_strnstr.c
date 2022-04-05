/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:48:13 by asibille          #+#    #+#             */
/*   Updated: 2022/01/12 17:45:03 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*ptr1;
	const char	*ptr2;
	size_t		len_copy;
	int			out;

	if (ft_strlen(needle) == 0)
		return ((char *) haystack);
	while (*haystack && (--len + 1) > 0)
	{
		out = 0;
		ptr1 = needle;
		ptr2 = haystack;
		len_copy = len + 2;
		while (*ptr1 && *ptr2 && --len_copy > 0)
		{
			if (*ptr1 != *ptr2)
				out = 1;
			++ptr1;
			++ptr2;
		}
		if (!out && len_copy >= 0 && *ptr1 == '\0')
			return ((char *) haystack);
		++haystack;
	}
	return (0);
}

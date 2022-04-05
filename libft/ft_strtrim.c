/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:54:01 by asibille          #+#    #+#             */
/*   Updated: 2022/01/11 12:42:36 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_find(char c, const char *s)
{
	int	in;

	in = 0;
	while (*s)
	{
		if (*s == c)
			in = 1;
		++s;
	}
	return (in);
}

static size_t	ft_find_malsize(char const *s1, char const *set)
{
	size_t	mal_size;

	mal_size = 0;
	while (ft_find(*s1, set))
			++s1;
	if (*s1 == '\0')
		return (0);
	while (*s1)
	{
		++mal_size;
		++s1;
	}
	--s1;
	while (ft_find(*s1, set))
	{
		--mal_size;
		--s1;
	}
	return (mal_size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	char	*ptr_cpy;
	size_t	mal_size;

	if (!s1 || !set)
		return (NULL);
	mal_size = ft_find_malsize(s1, set);
	ptr = malloc(sizeof(*s1) * (mal_size + 1));
	if (!ptr)
		return (NULL);
	ptr_cpy = ptr;
	while (ft_find(*s1, set))
		++s1;
	while (mal_size)
	{
		*ptr = *s1;
		++ptr;
		++s1;
		--mal_size;
	}
	*ptr = 0;
	return (ptr_cpy);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:13:30 by asibille          #+#    #+#             */
/*   Updated: 2022/01/10 17:42:34 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{	
	char	*ptr;
	int		len;
	int		i;

	len = ft_strlen(s1);
	ptr = malloc (len + 1);
	if (!ptr)
		return (NULL);
	i = -1;
	while (++i <= len)
		ptr[i] = s1[i];
	return (ptr);
}

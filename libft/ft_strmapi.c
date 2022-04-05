/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 09:51:37 by asibille          #+#    #+#             */
/*   Updated: 2022/01/11 09:11:53 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	i;	

	if (!s || !f)
		return (NULL);
	ptr = malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (!ptr)
		return (NULL);
	i = -1;
	while (s[++i])
		ptr[i] = (*f)(i, s[i]);
	ptr[i] = 0;
	return (ptr);
}

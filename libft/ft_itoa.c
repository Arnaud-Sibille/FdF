/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:34:39 by asibille          #+#    #+#             */
/*   Updated: 2022/01/12 16:49:30 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_find_div(long n2)
{
	long	div;

	div = 10;
	while (n2 / div)
		div *= 10;
	return (div / 10);
}

static int	ft_malsize(long n2)
{
	int		mal_size;
	long	div;

	mal_size = 1;
	if (n2 < 0)
	{
		n2 = -n2;
		++mal_size;
	}
	div = ft_find_div(n2);
	while (div > 1)
	{
		++mal_size;
		div = div / 10;
	}
	return (mal_size);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	char	*ptr_cpy;
	long	div;
	long	n2;

	n2 = (long) n;
	ptr = malloc(sizeof(char) * (ft_malsize(n2) + 1));
	if (!ptr)
		return (NULL);
	ptr_cpy = ptr;
	if (n2 < 0)
	{
		n2 = -n2;
		*(ptr++) = '-';
	}
	div = ft_find_div(n2);
	while (div > 1)
	{
		*(ptr++) = (n2 / div) + '0';
		n2 = n2 % div;
		div = div / 10;
	}
	*ptr = n2 + '0';
	*(ptr + 1) = 0;
	return (ptr_cpy);
}

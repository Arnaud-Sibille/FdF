/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:09:16 by asibille          #+#    #+#             */
/*   Updated: 2022/01/10 17:29:46 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_find_div_bis(long n)
{
	long	div;

	div = 10;
	while (n / div)
		div *= 10;
	return (div / 10);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	n2;
	long	div;

	n2 = (long) n;
	if (n2 < 0)
	{
		n2 = -n2;
		ft_putchar_fd('-', fd);
	}
	div = ft_find_div_bis(n2);
	while (div > 1)
	{
		ft_putchar_fd((n2 / div) + '0', fd);
		n2 = n2 % div;
		div = div / 10;
	}
	ft_putchar_fd(n2 + '0', fd);
}

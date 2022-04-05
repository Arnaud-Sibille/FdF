/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_axis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:30:35 by asibille          #+#    #+#             */
/*   Updated: 2022/02/28 17:49:25 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_axis(t_data *fdf)
{
	double	x;
	double	y;
	double	z;
	double	max;

	max = sqrt(HEIGHT * HEIGHT + WIDTH * WIDTH);
	x = -1;
	while (++x < max)
	{
		y = (x * sin(fdf->tx)) + fdf->oord;
		my_mlx_pixel_put(fdf, (x * cos(fdf->tx)) + fdf->oabs, y, TURQUOISE);
	}
	y = -1;
	while (++y < max)
	{
		x = (y * cos(fdf->ty)) + fdf->oabs;
		my_mlx_pixel_put(fdf, x, (y * sin(fdf->ty)) + fdf->oord, TURQUOISE);
	}
	z = -1;
	while (++z < max)
	{
		x = (z * cos(fdf->tz)) + fdf->oabs;
		my_mlx_pixel_put(fdf, x, (z * sin(fdf->tz)) + fdf->oord, TURQUOISE);
	}
}

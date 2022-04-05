/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:31:23 by asibille          #+#    #+#             */
/*   Updated: 2022/03/04 17:11:10 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *fdf, int x, int y, int color)
{
	char	*dst;

	if (color > 0x00FFFFFF)
		color = 0x00FFFFFF;
	else if (color < 0)
		color = 0;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = fdf->addr + (y * fdf->ll + x * (fdf->bpp / 8));
		*(unsigned int *) dst = color;
	}
}

static int	ft_dist(t_cord pt1, t_cord pt2)
{
	double	dist;

	dist = sqrt(pow((pt2.x - pt1.x), 2) + pow((pt2.y - pt1.y), 2));
	return (dist);
}

static size_t	col_to_hex(int red, int green, int blue)
{
	size_t	hex;

	hex = blue + 256 * green + 65536 * red;
	return (hex);
}

static void	ft_link(t_data *fdf, t_cord pt1, t_cord pt2)
{
	double	nbpoints;
	double	habs;
	double	hord;
	double	hred;
	double	hgreen;

	nbpoints = ft_dist(pt1, pt2);
	habs = (pt2.x - pt1.x) / nbpoints;
	hord = (pt2.y - pt1.y) / nbpoints;
	hred = (pt2.r - pt1.r) / nbpoints;
	hgreen = (pt2.g - pt1.g) / nbpoints;
	while (nbpoints >= 0)
	{
		my_mlx_pixel_put(fdf, pt1.x, pt1.y, col_to_hex(pt1.r, pt1.g, pt1.b));
		pt1.x += habs;
		pt1.y += hord;
		pt1.r += hred;
		pt1.g += hgreen;
		pt1.b += (pt2.b - pt1.b) / nbpoints;
		--nbpoints;
	}
}

void	ft_linkall(t_data *fdf, t_cord *ca, int nbrow, int nbcol)
{
	int	i;
	int	j;

	i = 0;
	while (i < nbrow)
	{
		j = 0;
		while (j < nbcol)
		{
			if (i < nbrow - 1)
				ft_link(fdf, ca[i * nbcol + j], ca[(i + 1) * nbcol + j]);
			if (j < nbcol - 1)
				ft_link(fdf, ca[i * nbcol + j], ca[i * nbcol + j + 1]);
			++j;
		}
		++i;
	}
}

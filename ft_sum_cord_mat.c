/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sum_cord_mat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:31:31 by asibille          #+#    #+#             */
/*   Updated: 2022/02/28 21:42:35 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	ft_max(int *mat, int size)
{
	double	max;
	int		i;

	i = 0;
	max = mat[0];
	while (i < size)
	{
		if (mat[i] > max)
			max = mat[i];
		++i;
	}
	return (max);
}

static double	ft_min(int *mat, int size)
{
	double	min;
	int		i;

	i = 0;
	min = mat[0];
	while (i < size)
	{
		if (mat[i] < min)
			min = mat[i];
		++i;
	}
	return (min);
}

static void	ft_bonus(t_cord *ca, t_data fdf, int i, int j)
{
	ca[i * fdf.nbcol + j].r = 255.0 - (double) i * 255.0 / (double) fdf.nbrow;
	ca[i * fdf.nbcol + j].g = 255.0 - (double) j * 255.0 / (double) fdf.nbcol;
	ca[i * fdf.nbcol + j].b = 255.0 - ((double)(fdf.mat[i * fdf.nbcol + j])
			- fdf.min) * 255.0 / (fdf.max - fdf.min);
}

void	ft_sum_cord_mat(t_cord *ca, t_data fdf)
{
	int		i;
	int		j;

	fdf.min = ft_min(fdf.mat, fdf.nbrow * fdf.nbcol);
	fdf.max = ft_max(fdf.mat, fdf.nbrow * fdf.nbcol);
	i = -1;
	while (++i < fdf.nbrow)
	{
		j = -1;
		while (++j < fdf.nbcol)
		{
			ca[i * fdf.nbcol + j].x += fdf.hz
				* cos(fdf.tz) * fdf.mat[i * fdf.nbcol + j];
			ca[i * fdf.nbcol + j].y += fdf.hz
				* sin(fdf.tz) * fdf.mat[i * fdf.nbcol + j];
			if (fdf.bonus)
				ft_bonus(ca, fdf, i, j);
			else
			{
				ca[i * fdf.nbcol + j].r = fdf.colmat[i * fdf.nbcol + j].red;
				ca[i * fdf.nbcol + j].g = fdf.colmat[i * fdf.nbcol + j].green;
				ca[i * fdf.nbcol + j].b = fdf.colmat[i * fdf.nbcol + j].blue;
			}
		}
	}
}

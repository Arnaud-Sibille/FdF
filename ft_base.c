/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:31:09 by asibille          #+#    #+#             */
/*   Updated: 2022/03/28 17:47:06 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cord	*ft_base(t_data *fdf)
{
	t_cord	*ca;
	int		i;
	int		j;

	ca = malloc(sizeof(t_cord) * fdf->nbrow * fdf->nbcol);
	if (!ca)
		ft_exit(fdf);
	i = -1;
	while (++i < fdf->nbrow)
	{
		j = -1;
		while (++j < fdf->nbcol)
		{
			ca[i * fdf->nbcol + j].x = cos(fdf->tx)
				* i * fdf->hx + cos(fdf->ty) * j * fdf->hy;
			ca[i * fdf->nbcol + j].y = sin(fdf->tx)
				* i * fdf->hx + sin(fdf->ty) * j * fdf->hy;
			ca[i * fdf->nbcol + j].x += fdf->oabs;
			ca[i * fdf->nbcol + j].y += fdf->oord;
		}
	}
	return (ca);
}

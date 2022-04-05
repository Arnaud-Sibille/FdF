/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:53:05 by asibille          #+#    #+#             */
/*   Updated: 2022/03/29 07:10:25 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_param(t_data *fdf)
{
	fdf->oabs = (WIDTH / 2);
	fdf->oord = (HEIGHT / 4);
	fdf->tx = (5 * PI / 6.0);
	fdf->ty = (PI / 6.0);
	fdf->tz = (-PI / 2.0);
	fdf->hx = (500 / fdf->nbrow);
	fdf->hy = (500 / fdf->nbrow);
	fdf->hz = 1;
	fdf->bonus = 0;
	fdf->instrcol = RED;
	fdf->fontcol = BLACK;
	fdf->zoom = 1.0;
	fdf->zoomfocabs = WIDTH / 2;
	fdf->zoomfocord = HEIGHT / 2;
	fdf->axis = 0;
}

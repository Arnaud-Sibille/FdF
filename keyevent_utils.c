/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevent_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:41:54 by asibille          #+#    #+#             */
/*   Updated: 2022/03/01 12:03:24 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_key1(int key, t_data *fdf)
{
	if (key == 124)
		fdf->oabs += 10;
	else if (key == 123)
		fdf->oabs -= 10;
	else if (key == 125)
		fdf->oord += 10;
	else if (key == 126)
		fdf->oord -= 10;
	else if (key == 6)
	{
		fdf->tx -= PI / 42.0;
		fdf->ty -= PI / 42.0;
	}
	else if (key == 7)
	{
		fdf->tx += PI / 42.0;
		fdf->ty += PI / 42.0;
	}
}

void	ft_key2(int key, t_data *fdf)
{
	if (key == 12)
		fdf->tx += PI / 6.0;
	else if (key == 13)
		fdf->tx -= PI / 6.0;
	else if (key == 14)
		fdf->ty += PI / 6.0;
	else if (key == 15)
		fdf->ty -= PI / 6.0;
	else if (key == 17)
		fdf->tz += PI / 6.0;
	else if (key == 16)
		fdf->tz -= PI / 6.0;
	else if (key == 48)
		fdf->axis = !fdf->axis;
}

void	ft_key3(int key, t_data *fdf)
{
	if (key == 11)
		fdf->bonus = !fdf->bonus;
	else if (key == 0)
		fdf->hx += 1;
	else if (key == 1)
		fdf->hx -= 1;
	else if (key == 2)
		fdf->hy += 1;
	else if (key == 3)
		fdf->hy -= 1;
	else if (key == 5)
		fdf->hz += 1;
	else if (key == 4)
		fdf->hz -= 1;
	else if (key == 24)
		fdf->zoom *= 1.1;
	else if (key == 27)
		fdf->zoom /= 1.1;
}

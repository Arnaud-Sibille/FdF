/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:27:20 by asibille          #+#    #+#             */
/*   Updated: 2022/03/28 17:45:29 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_fill(t_data *fdf)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			my_mlx_pixel_put(fdf, x, y, fdf->fontcol);
			++y;
		}
		++x;
	}
}

void	ft_instr(t_data fdf)
{
	int	y;
	int	col;

	col = fdf.instrcol;
	y = 20;
	mlx_string_put(fdf.mlx, fdf.mlx_win, 5, y * 1, col, "O abs : arrows");
	mlx_string_put(fdf.mlx, fdf.mlx_win, 5, y * 2, col, "O ord : arrows");
	mlx_string_put(fdf.mlx, fdf.mlx_win, 5, y * 3, col, "Step x: 'A' & 'S'");
	mlx_string_put(fdf.mlx, fdf.mlx_win, 5, y * 4, col, "Step y: 'D' & 'F'");
	mlx_string_put(fdf.mlx, fdf.mlx_win, 5, y * 5, col, "Step z: 'G' & 'H'");
	mlx_string_put(fdf.mlx, fdf.mlx_win, 5, y * 6, col, "Ang x : 'Q' & 'W'");
	mlx_string_put(fdf.mlx, fdf.mlx_win, 5, y * 7, col, "Ang y : 'E' & 'R'");
	mlx_string_put(fdf.mlx, fdf.mlx_win, 5, y * 8, col, "Ang z : 'T' & 'Y'");
	mlx_string_put(fdf.mlx, fdf.mlx_win, 5, y * 9, col, "Rot   : 'Z' & 'X'");
	mlx_string_put(fdf.mlx, fdf.mlx_win, 5, y * 10, col, "Zoom  : '+' & '-'");
	mlx_string_put(fdf.mlx, fdf.mlx_win, 5, y * 11, col, "Axis  : tab");
	mlx_string_put(fdf.mlx, fdf.mlx_win, 5, y * 12, col, "Bonus : 'B'");
}

static void	ft_update_data(int key, t_data *fdf)
{
	ft_key1(key, fdf);
	ft_key2(key, fdf);
	ft_key3(key, fdf);
}

static void	ft_zoom(t_cord *ca, t_data fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf.nbrow)
	{
		j = 0;
		while (j < fdf.nbcol)
		{
			ca[i * fdf.nbcol + j].x = fdf.zoomfocabs
				+ fdf.zoom * (ca[i * fdf.nbcol + j].x - fdf.zoomfocabs);
			ca[i * fdf.nbcol + j].y = fdf.zoomfocord
				+ fdf.zoom * (ca[i * fdf.nbcol + j].y - fdf.zoomfocord);
			++j;
		}
		++i;
	}
}

int	keyevent(int key, t_data *fdf)
{
	t_cord	*cordarray;

	if (key == 53)
		ft_exit(fdf);
	if (key == 49)
		ft_fill_param(fdf);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
		ft_exit(fdf);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->ed);
	ft_update_data(key, fdf);
	ft_fill(fdf);
	if (fdf->axis && fdf->zoom == 1)
		ft_axis(fdf);
	cordarray = ft_base(fdf);
	ft_sum_cord_mat(cordarray, *fdf);
	ft_zoom(cordarray, *fdf);
	ft_linkall(fdf, cordarray, fdf->nbrow, fdf->nbcol);
	free(cordarray);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img, 0, 0);
	mlx_destroy_image(fdf->mlx, fdf->img);
	ft_instr(*fdf);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:22:35 by asibille          #+#    #+#             */
/*   Updated: 2022/03/29 07:07:55 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init(t_data *fdf, char *s)
{
	fdf->mlx_win = NULL;
	fdf->mat = NULL;
	fdf->colmat = NULL;
	ft_input_to_mat(fdf, s);
	ft_fill_param(fdf);
	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF");
	if (!fdf->mlx_win)
		ft_exit(fdf);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
		ft_exit(fdf);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->ed);
}

int	main(int argc, char **argv)
{
	t_data	fdf;
	t_cord	*cordarray;

	if (argc == 2)
	{
		ft_init(&fdf, argv[1]);
		cordarray = ft_base(&fdf);
		ft_sum_cord_mat(cordarray, fdf);
		ft_linkall(&fdf, cordarray, fdf.nbrow, fdf.nbcol);
		free(cordarray);
		mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, fdf.img, 0, 0);
		mlx_destroy_image(fdf.mlx, fdf.img);
		ft_instr(fdf);
		mlx_key_hook(fdf.mlx_win, keyevent, &fdf);
		mlx_hook(fdf.mlx_win, 17, 1, ft_exit, &fdf);
		mlx_loop(fdf.mlx);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:22:32 by asibille          #+#    #+#             */
/*   Updated: 2022/03/29 07:00:58 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# define RED 0x00FF0000
# define WHITE 0x00FFFFFF
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define BLACK 0x000000
# define YELLOW 0x00FFFF00
# define TURQUOISE 0x0000FFFF
# define PI 3.1415926
# define BUFFERSIZE 50000
# define HEIGHT 1080
# define WIDTH 1920

typedef struct s_colors
{
	double	red;
	double	green;
	double	blue;
}				t_colors;

typedef struct s_cord
{
	double	x;
	double	y;
	double	r;
	double	g;
	double	b;
}			t_cord;

typedef struct s_data {
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bpp;
	int			ll;
	int			ed;
	int			nbcol;
	int			nbrow;
	double		oabs;
	double		oord;
	double		tx;
	double		ty;
	double		tz;
	double		hx;
	double		hy;
	double		hz;
	double		bonus;
	int			*mat;
	t_colors	*colmat;
	double		max;
	double		min;
	int			instrcol;
	int			fontcol;
	double		zoom;
	double		zoomfocabs;
	double		zoomfocord;
	int			axis;
}				t_data;

char	*ft_strjoin_buffer(char *s1);
char	*ft_file_to_string(char *file);
int		ft_nbrows(const char *str);
int		ft_nbcol(const char *str);
void	ft_input_to_mat(t_data *fdf, char *file);
void	ft_linkall(t_data *fdf, t_cord *cordarray, int nbrow, int nbcol);
t_cord	*ft_base(t_data *fdf);
void	my_mlx_pixel_put(t_data *fdf, int x, int y, int color);
void	ft_axis(t_data *fdf);
void	ft_sum_cord_mat(t_cord *ca, t_data fdf);
void	ft_fill_param(t_data *fdf);
int		keyevent(int key, t_data *fdf);
void	ft_instr(t_data fdf);
void	ft_key1(int key, t_data *fdf);
void	ft_key2(int key, t_data *fdf);
void	ft_key3(int key, t_data *fdf);
int		ft_exit(t_data *fdf);
void	ft_nocolor(t_colors *col);
#endif
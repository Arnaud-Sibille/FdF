/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_mat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:23:22 by asibille          #+#    #+#             */
/*   Updated: 2022/03/30 09:55:37 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned int	ft_atox(char *arr, size_t size)
{
	unsigned int	i;

	i = 0;
	while (size > 0)
	{
		if (*arr >= '0' && *arr <= '9')
			i = i * 16 + *arr - '0';
		else if (*arr >= 'A' && *arr <= 'F')
			i = i * 16 + 10 + *arr - 'A';
		else if (*arr >= 'a' && *arr <= 'f')
			i = i * 16 + 10 + *arr - 'a';
		++arr;
		--size;
	}
	return (i);
}

static void	ft_fill_col(t_colors *col, char *s, int index)
{
	if (index == 0)
	{
		col->red = 0;
		col->green = 0;
		col->blue = ft_atox(s + 3, 2);
	}
	else if (index == 1)
	{
		col->red = 0;
		col->green = ft_atox(s + 3, 2);
		col->blue = ft_atox(s + 5, 2);
	}
	else
	{
		col->red = ft_atox(s + 3, 2);
		col->green = ft_atox(s + 5, 2);
		col->blue = ft_atox(s + 7, 2);
	}
}

static int	ft_color(t_colors *col, char *s)
{
	int	max_ind;

	max_ind = 0;
	while (ft_isalnum(s[max_ind + 1]))
		++max_ind;
	if (max_ind >= 2)
	{
		if (max_ind == 4)
			ft_fill_col(col, s, 0);
		else if (max_ind == 6)
			ft_fill_col(col, s, 1);
		else if (max_ind == 8)
			ft_fill_col(col, s, 2);
	}
	else
		ft_nocolor(col);
	return (max_ind + 1);
}

static void	ft_str_to_intarr(char *s, int *intarr, t_colors *col)
{
	int	i;

	i = -1;
	while (*s)
	{
		if (ft_isdigit(*s) || *s == '-')
		{
			intarr[++i] = atoi(s);
			while (ft_isdigit(*s) || *s == '-')
				++s;
			if (*s == ',')
				s += ft_color(col + i, s);
			else
				ft_nocolor(col + i);
		}
		else
			++s;
	}
}

void	ft_input_to_mat(t_data *fdf, char *file)
{
	char		*s;
	t_colors	*col;
	int			*mat;

	s = ft_file_to_string(file);
	fdf->nbrow = ft_nbrows(s);
	fdf->nbcol = ft_nbcol(s);
	col = malloc(sizeof(t_colors) * fdf->nbrow * fdf->nbcol);
	mat = malloc(sizeof(int) * fdf->nbrow * fdf->nbcol);
	if (!col || !mat)
		ft_exit(fdf);
	ft_str_to_intarr(s, mat, col);
	free(s);
	fdf->colmat = col;
	fdf->mat = mat;
}

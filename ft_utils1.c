/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:54:37 by asibille          #+#    #+#             */
/*   Updated: 2022/03/28 19:27:37 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strjoin_buffer(char *s1)
{
	char	*ptr;
	int		s1_len;
	char	*ptr_cpy;
	char	*s1_cpy;

	s1_cpy = s1;
	s1_len = ft_strlen(s1);
	ptr = ft_calloc((s1_len + BUFFERSIZE + 1), sizeof(char));
	if (!ptr)
	{
		free(s1_cpy);
		exit(-1);
	}
	ptr_cpy = ptr;
	if (!ptr)
		return (NULL);
	if (s1)
	{
		while (*s1)
			*(ptr++) = *(s1++);
	}
	free(s1_cpy);
	return (ptr_cpy);
}

char	*ft_file_to_string(char *file)
{
	int		fd;
	char	*str;
	int		ret ;

	str = ft_calloc(sizeof(char *), BUFFERSIZE + 1);
	if (!str)
		exit(-1);
	fd = open(file, O_RDONLY);
	ret = read(fd, str, BUFFERSIZE);
	if (ret == -1)
	{
		free(str);
		write(1, "Can't read file\n", 16);
		exit(-1);
	}
	while (ret > 0)
	{
		ret = read(fd, str + ft_strlen(str), BUFFERSIZE);
		str = ft_strjoin_buffer(str);
	}
	close(fd);
	return (str);
}

int	ft_nbrows(const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '\n')
			++count;
		++str;
	}
	--str;
	if (*str != '\n')
		++count;
	return (count);
}

int	ft_nbcol(const char *str)
{
	int	count;

	count = 0;
	while (*str == ' ')
		++str;
	while (*str != '\n')
	{
		if (*str == ' ')
		{
			++count;
			while (*str == ' ')
				++str;
		}
		else
			++str;
	}
	--str;
	if (*str != ' ')
		++count;
	return (count);
}

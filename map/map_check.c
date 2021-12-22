/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:20:02 by fel-maac          #+#    #+#             */
/*   Updated: 2021/12/20 10:10:34 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_characters(char *dst)
{
	int	i;

	i = 0;
	while (dst[i])
	{
		if (dst[i] != '0' && dst[i] != '1' && dst[i] != 'P' && dst[i] != 'C'
			&& dst[i] != 'E' && dst[i] != '\n')
		{
			free(dst);
			error_exit("map contains unknown character");
		}
		i++;
	}
}

static int	check(char *dst, char c)
{
	int	i;

	i = 0;
	while (dst[i])
	{
		if (dst[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	check_if_available(char *dst)
{
	if (!check(dst, '0'))
	{
		free(dst);
		error_exit("character 0 is missing");
	}
	if (!check(dst, '1'))
	{
		free(dst);
		error_exit("character 1 is missing");
	}
	if (!check(dst, 'P'))
	{
		free(dst);
		error_exit("character P is missing");
	}
	if (!check(dst, 'C'))
	{
		free(dst);
		error_exit("character C is missing");
	}
	if (!check(dst, 'E'))
	{
		free(dst);
		error_exit("character E is missing");
	}
}

void	check_if_rectangular(char **data)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(data[i]);
	while (data[++i])
	{
		if (ft_strlen(data[i]) != len)
			error_exit("map not rectangular");
	}
}

void	calc_dimensions(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->data[j][i])
		i++;
	map->width = i * IMG_SIZE;
	while (map->data[j])
		j++;
	map->height = j * IMG_SIZE;
	if (map->width > 5120 || map->height > 2880)
		error_exit("map too big");
}

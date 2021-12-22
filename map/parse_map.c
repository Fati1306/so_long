/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:14:33 by fel-maac          #+#    #+#             */
/*   Updated: 2021/12/16 14:20:16 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	read_map(int fd, char **dst)
{
	char	*src;
	int		check;

	check = 1;
	src = ft_strdup(".");
	if (src == NULL)
	{
		free(*dst);
		perror_exit();
	}
	while (check != 0)
	{
		check = read(fd, src, 1);
		if (check == 0)
			break ;
		if (check < 0)
		{
			free(*dst);
			perror_exit();
		}
		*dst = ft_strjoin(*dst, src);
	}
	free(src);
	close(fd);
}

static int	count_stars(char *dst)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (dst[i])
	{
		if (dst[i] == 'C')
			count++;
		i++;
	}
	return (count);
}

static void	check_newlines(char *dst)
{
	int	i;

	i = 0;
	while (dst[i])
	{
		if (dst[i] == '\n' && dst[i + 1] == '\n')
		{
			free(dst);
			error_exit("invalid map");
		}
		i++;
	}
}

void	parse_map(char *file, t_map *map)
{
	int		fd;
	char	*dst;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		perror_exit();
	dst = ft_strdup("");
	if (dst == NULL)
		perror_exit();
	read_map(fd, &dst);
	check_newlines(dst);
	check_characters(dst);
	check_if_available(dst);
	map->goal = count_stars(dst);
	map->data = ft_split(dst, '\n');
	free(dst);
	check_if_rectangular(map->data);
	check_walls(map->data);
	calc_dimensions(map);
}

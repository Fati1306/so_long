/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_walls_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:07:26 by fel-maac          #+#    #+#             */
/*   Updated: 2021/12/16 14:19:50 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_upper_wall(char **data)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (data[0][++i])
	{
		if (data[0][i] != '1')
			error_exit("upper wall does not surround map");
	}
}

static void	check_lower_wall(char **data)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (data[j])
		j++;
	while (data[j - 1][++i])
	{
		if (data[j - 1][i] != '1')
			error_exit("lower wall does not surround map");
	}
}

static void	check_side_wall(char **data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data[j][i])
		i++;
	i--;
	while (data[j])
	{
		if (data[j][0] != '1' || data[j][i] != '1')
			error_exit("side wall does not surround map");
		j++;
	}	
}

void	check_walls(char **data)
{
	check_upper_wall(data);
	check_lower_wall(data);
	check_side_wall(data);
}

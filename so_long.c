/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:26:31 by fel-maac          #+#    #+#             */
/*   Updated: 2021/12/16 14:07:54 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *error)
{
	printf("Error\n%s\n", error);
	exit(1);
}

void	perror_exit(void)
{
	perror(NULL);
	exit(1);
}

static void	check_format(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 4] == '.' && s[i - 3] == 'b' && s[i -2] == 'e' && s[i - 1] == 'r')
		return ;
	else
		error_exit("invalid file format");
}

int	main(int ac, char **av)
{
	t_data			frame;
	t_map			map;

	if (ac == 2)
	{
		check_format(av[1]);
		parse_map(av[1], &map);
	}
	else
		error_exit("incorrect amount of arguments passed to function");
	frame.map = &map;
	init_game(&frame);
	return (0);
}

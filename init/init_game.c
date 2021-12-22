/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:19:43 by fel-maac          #+#    #+#             */
/*   Updated: 2021/12/22 11:19:36 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_mlx_win(t_data *frame)
{
	void			*mlx;
	void			*win;

	mlx = NULL;
	win = NULL;
	mlx = mlx_init();
	if (mlx == NULL)
		error_exit("unable to initialize mlx");
	win = mlx_new_window(mlx, frame->map->width, frame->map->height, "so_long");
	if (win == NULL)
		error_exit("unable to create new window");
	frame->mlx = mlx;
	frame->window = win;
}

static void	null_structs_pointers(t_data *frame)
{
	frame->w = NULL;
	frame->f = NULL;
	frame->p = NULL;
	frame->c = NULL;
	frame->x = NULL;
}

void	init_game(t_data *frame)
{
	init_mlx_win(frame);
	null_structs_pointers(frame);
	init_tiles(frame);
	init_player(frame);
	init_collectible(frame);
	init_exit(frame);
	render_game(frame);
}

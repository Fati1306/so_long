/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:18:35 by fel-maac          #+#    #+#             */
/*   Updated: 2021/12/21 08:23:38 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_type(char *c, int x, int y, t_data *fr)
{
	if (*c == '1')
		mlx_put_image_to_window(fr->mlx, fr->window, fr->w->img, x, y);
	else
		mlx_put_image_to_window(fr->mlx, fr->window, fr->f->img, x, y);
	if (*c == 'C')
		render_collectible(fr, x, y, c);
	if (*c == 'E')
		render_exit(fr, x, y);
	if (*c == 'P' && fr->p->start == 1)
		render_player(fr, x, y);
	if (fr->p->start == 0)
		render_player(fr, fr->p->pos[0], fr->p->pos[1]);
}

int	render_frame(t_data *frame)
{
	int	i;
	int	j;
	int	x;
	int	y;

	j = 0;
	y = 0;
	while (frame->map->data[j])
	{
		i = 0;
		x = 0;
		while (frame->map->data[j][i])
		{
			check_type(&frame->map->data[j][i], x, y, frame);
			i++;
			x += IMG_SIZE;
		}
		j++;
		y += IMG_SIZE;
	}
	return (0);
}

static int	key_hook(int keycode, t_data *frame)
{
	if (keycode == 0 && frame->p->pos[0] > IMG_SIZE)
		move_left(frame);
	if (keycode == 2 && frame->p->pos[0] < frame->map->width - IMG_SIZE * 2)
		move_right(frame);
	if (keycode == 13 && frame->p->pos[1] > IMG_SIZE)
		move_up(frame);
	if (keycode == 1 && frame->p->pos[1] < frame->map->height - IMG_SIZE * 2)
		move_down(frame);
	if (keycode == 53)
		exit(0);
	return (0);
}

static int	exit_hook(int mousecode, t_data *frame)
{
	(void)frame;
	(void)mousecode;
	exit(0);
	return (0);
}

void	render_game(t_data *frame)
{
	mlx_loop_hook(frame->mlx, render_frame, frame);
	mlx_hook(frame->window, 2, 1L << 0, key_hook, frame);
	mlx_hook(frame->window, 17, 0L, exit_hook, frame);
	mlx_loop(frame->mlx);
}

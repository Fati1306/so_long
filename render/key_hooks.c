/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:41:49 by fel-maac          #+#    #+#             */
/*   Updated: 2021/12/20 09:27:44 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_for_wall(int x, int y, t_data *frame)
{
	x /= IMG_SIZE;
	y /= IMG_SIZE;
	if (frame->map->data[y][x] == '1')
		return (0);
	return (1);
}

void	move_left(t_data *frame)
{
	if (check_for_wall(frame->p->pos[0] - MOVE, frame->p->pos[1], frame))
	{
		frame->p->start = 0;
		frame->p->pos[0] -= MOVE;
		frame->p->moves++;
		printf("moves: %d\n", frame->p->moves);
		render_frame(frame);
	}
}

void	move_right(t_data *frame)
{
	if (check_for_wall(frame->p->pos[0] + MOVE, frame->p->pos[1], frame))
	{
		frame->p->start = 0;
		frame->p->pos[0] += MOVE;
		frame->p->moves++;
		printf("moves: %d\n", frame->p->moves);
		render_frame(frame);
	}
}

void	move_up(t_data *frame)
{
	if (check_for_wall(frame->p->pos[0], frame->p->pos[1] - MOVE, frame))
	{
		frame->p->start = 0;
		frame->p->pos[1] -= MOVE;
		frame->p->moves++;
		printf("moves: %d\n", frame->p->moves);
		render_frame(frame);
	}
}

void	move_down(t_data *frame)
{
	if (check_for_wall(frame->p->pos[0], frame->p->pos[1] + MOVE, frame))
	{
		frame->p->start = 0;
		frame->p->pos[1] += MOVE;
		frame->p->moves++;
		printf("moves: %d\n", frame->p->moves);
		render_frame(frame);
	}
}

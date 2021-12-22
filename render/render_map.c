/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:15:51 by fel-maac          #+#    #+#             */
/*   Updated: 2021/12/21 08:22:03 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_collectible(t_data *fr, int x, int y, char *c)
{
	if (fr->p->pos[0] == x && fr->p->pos[1] == y)
	{
		*c = '0';
		fr->map->goal--;
	}
	else
		mlx_put_image_to_window(fr->mlx, fr->window, fr->c->img, x, y);
}

void	render_exit(t_data *fr, int x, int y)
{
	if (fr->p->pos[0] == x && fr->p->pos[1] == y && fr->map->goal == 0)
	{
		mlx_put_image_to_window(fr->mlx, fr->window, fr->p->img, x, y);
		exit(0);
	}
	else
		mlx_put_image_to_window(fr->mlx, fr->window, fr->x->img, x, y);
}

void	render_player(t_data *fr, int x, int y)
{
	if (fr->p->start == 1)
	{
		fr->p->pos[0] = x;
		fr->p->pos[1] = y;
	}
	mlx_put_image_to_window(fr->mlx, fr->window, fr->p->img, x, y);
}

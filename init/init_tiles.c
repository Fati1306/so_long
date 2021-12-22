/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:34:30 by fel-maac          #+#    #+#             */
/*   Updated: 2021/12/16 14:09:31 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_tiles(t_data *fr)
{
	fr->w = (t_tile *) malloc(sizeof(t_tile));
	if (fr->w == NULL)
		perror_exit();
	fr->f = (t_tile *) malloc(sizeof(t_tile));
	if (fr->f == NULL)
		perror_exit();
	fr->w->img = mlx_xpm_file_to_image(fr->mlx, WALL, &fr->w->wi, &fr->w->he);
	fr->f->img = mlx_xpm_file_to_image(fr->mlx, FLOOR, &fr->f->wi, &fr->f->he);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:51:49 by fel-maac          #+#    #+#             */
/*   Updated: 2021/12/21 08:20:12 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_player(t_data *fr)
{
	fr->p = (t_character *) malloc(sizeof(t_character));
	if (fr->p == NULL)
		perror_exit();
	fr->p->img = mlx_xpm_file_to_image(fr->mlx, PL, &fr->p->wi, &fr->p->he);
	fr->p->pos[0] = IMG_SIZE;
	fr->p->pos[1] = IMG_SIZE;
	fr->p->moves = 0;
	fr->p->start = 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_collectible.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:30:15 by fel-maac          #+#    #+#             */
/*   Updated: 2021/12/21 08:20:32 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_collectible(t_data *fr)
{
	fr->c = (t_collectible *) malloc(sizeof(t_collectible));
	if (fr->c == NULL)
		perror_exit();
	fr->c->img = mlx_xpm_file_to_image(fr->mlx, STAR, &fr->c->wi, &fr->c->he);
}

void	init_exit(t_data *fr)
{
	fr->x = (t_collectible *) malloc(sizeof(t_collectible));
	if (fr->x == NULL)
		perror_exit();
	fr->x->img = mlx_xpm_file_to_image(fr->mlx, EXIT, &fr->x->wi, &fr->x->he);
}

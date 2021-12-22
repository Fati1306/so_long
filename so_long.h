/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:31:41 by fel-maac          #+#    #+#             */
/*   Updated: 2021/12/22 11:14:45 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_map
{
	char	**data;
	int		width;
	int		height;
	int		goal;
}	t_map;

//w = wall f = floor p = player c = collectible x = exit 
//wi = width he = height pos = position
typedef struct s_tile
{
	void	*img;
	int		wi;
	int		he;
}	t_tile;

typedef struct s_character
{
	void	*img;
	int		wi;
	int		he;
	int		pos[2];
	int		moves;
	int		start;
}	t_character;

typedef struct s_collectible
{
	void	*img;
	int		wi;
	int		he;
}	t_collectible;

typedef struct s_data
{
	void			*mlx;
	void			*window;
	t_map			*map;
	t_tile			*w;
	t_tile			*f;
	t_character		*p;
	t_collectible	*c;
	t_collectible	*x;
}	t_data;

# define IMG_SIZE 32
# define MOVE 32
# define WALL "assets/background/Floor.xpm"
# define FLOOR "assets/background/Wall.xpm"
# define PL "assets/character/Player.xpm"
# define STAR "assets/collectible/Star.xpm"
# define EXIT "assets/collectible/Exit.xpm"

void	error_exit(char *msg);
void	perror_exit(void);
void	parse_map(char *file, t_map *map);
char	*ft_strdup(char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
void	check_characters(char *dst);
void	check_if_available(char *dst);
char	**ft_split(char const *s, char c);
void	check_if_rectangular(char **data);
void	check_walls(char **data);
void	calc_dimensions(t_map *map);
void	init_game(t_data *frame);
void	init_tiles(t_data *fr);
void	init_player(t_data *fr);
void	init_collectible(t_data *fr);
void	init_exit(t_data *fr);

void	render_game(t_data *frame);
int		render_frame(t_data *frame);
void	render_collectible(t_data *fr, int x, int y, char *c);
void	render_exit(t_data *fr, int x, int y);
void	render_player(t_data *fr, int x, int y);

void	move_left(t_data *frame);
void	move_right(t_data *frame);
void	move_up(t_data *frame);
void	move_down(t_data *frame);

char	*ft_strdup(char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);

#endif

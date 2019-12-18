/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:03:39 by tmyrcell          #+#    #+#             */
/*   Updated: 2019/12/12 16:18:48 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

typedef	struct s_tetri	t_tetri;
struct		s_tetri
{
	char			name;
	int				coords[8];
	struct s_tetri	*next;
};

typedef	struct s_map	t_map;
struct		s_map
{
	char	*map;
	int		size;
};

int			check(int fd, char *line, t_tetri *result);
int			check_place(char *line);
t_tetri		*find_min_coords(t_tetri *result);
t_tetri		replace_coords(t_tetri *result, int min_x, int min_y);
t_tetri		*create_node(void);
void		read_coords(char *line, t_tetri **result);
t_tetri		push_back(t_tetri *result, char *line);
t_map		*map_create(int size);
int			write_on_map_main(t_map *mapa, t_tetri *result);
void		*replace_chr(void *str, int size);
int			fill_map(t_map *mapa, t_tetri *result);
int			write_on_map(t_map *map, t_tetri *result, int x);
void		clear_last(t_map *mapa, t_tetri *result, int x);
void		solve(t_tetri *result);
int			get_map_size(t_tetri *result);
int			count_tetriminos(t_tetri *result);
void		delete_map(t_map *mapa);
void		print_map(t_map *mapa);
int			check_cord_map(t_tetri *result, t_map *mapa, int count_x);
int         no_usage(void);
int         no_open(void);
int         error(int fd, t_tetri* result);
void        free_result(t_tetri *result);
t_tetri     *fillit(int fd, t_tetri *result);
int     check_last(int fd, int *temp_buf);

#endif

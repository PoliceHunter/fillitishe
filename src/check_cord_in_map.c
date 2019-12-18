/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cord_in_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:31:59 by tmyrcell          #+#    #+#             */
/*   Updated: 2019/12/12 14:34:07 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int		check_cord_map(t_tetri *result, t_map *mapa, int x)
{
	int i_x;
	int i_y;

	i_x = x % (mapa->size + 1);
	i_y = x / (mapa->size + 1);
	if (result->coords[0] + i_x < 0 || result->coords[0] + i_x > mapa->size)
		return (0);
	if (result->coords[2] + i_x < 0 || result->coords[1] + i_x > mapa->size)
		return (0);
	if (result->coords[4] + i_x < 0 || result->coords[2] + i_x > mapa->size)
		return (0);
	if (result->coords[6] + i_x < 0 || result->coords[3] + i_x > mapa->size)
		return (0);
	if (result->coords[1] + i_y < 0 || result->coords[1] + i_y > mapa->size)
		return (0);
	if (result->coords[3] + i_y < 0 || result->coords[3] + i_y > mapa->size)
		return (0);
	if (result->coords[5] + i_y < 0 || result->coords[5] + i_y > mapa->size)
		return (0);
	if (result->coords[7] + i_y < 0 || result->coords[7] + i_y > mapa->size)
		return (0);
	return (1);
}

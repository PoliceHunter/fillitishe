/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:36:57 by tmyrcell          #+#    #+#             */
/*   Updated: 2019/12/12 14:41:51 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int		write_on_map(t_map *mapa, t_tetri *result, int x)
{
	int n;

	n = mapa->size + 1;
	if (!check_cord_map(result, mapa, x))
		return (0);
	if (mapa->map[result->coords[0] + x + (n * result->coords[1])] != '.')
		return (0);
	if (mapa->map[result->coords[2] + x + (n * result->coords[3])] != '.')
		return (0);
	if (mapa->map[result->coords[4] + x + (n * result->coords[5])] != '.')
		return (0);
	if (mapa->map[result->coords[6] + x + (n * result->coords[7])] != '.')
		return (0);
	mapa->map[result->coords[0] + x + (n * result->coords[1])] = result->name;
	mapa->map[result->coords[2] + x + (n * result->coords[3])] = result->name;
	mapa->map[result->coords[4] + x + (n * result->coords[5])] = result->name;
	mapa->map[result->coords[6] + x + (n * result->coords[7])] = result->name;
	return (1);
}

int		write_on_map_main(t_map *mapa, t_tetri *result)
{
	int x;

	if (!result)
		return (1);
	x = 0;
	while (x < (mapa->size * mapa->size + mapa->size))
	{
		if (write_on_map(mapa, result, x))
		{
			if (write_on_map_main(mapa, result->next))
				return (1);
			else
				clear_last(mapa, result, x);
		}
		x++;
	}
	return (0);
}

int		fill_map(t_map *mapa, t_tetri *result)
{
	if (write_on_map_main(mapa, result))
	{
		print_map(mapa);
		return (1);
	}
	return (0);
}

void	solve(t_tetri *result)
{
	t_map	*mapa;
	int		size;

	mapa = map_create(get_map_size(result));
	size = mapa->size;
	while (!fill_map(mapa, result))
	{
		size++;
		delete_map(mapa);
		mapa = map_create(size);
	}
	free_result(result);
	delete_map(mapa);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jczech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:31:26 by jczech            #+#    #+#             */
/*   Updated: 2019/12/12 16:19:20 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int		count_tetriminos(t_tetri *result)
{
	int counter;

	counter = 0;
	while (result)
	{
		counter++;
		result = result->next;
	}
	return (counter);
}

int		get_map_size(t_tetri *result)
{
	int counter;
	int size;

	size = 1;
	counter = count_tetriminos(result);
	while (size * size < (counter * 4))
		size++;
	return (size);
}

void	*replace_chr(void *map, int size)
{
	int		i;
	int		tmp;
	char	*ptr;

	tmp = size;
	i = 0;
	ptr = (char *)map;
	while (ptr[i] != '\0')
	{
		if (i == size)
		{
			ptr[i] = '\n';
			size += tmp + 1;
		}
		i++;
	}
	ptr[--i] = '\0';
	return (map);
}

t_map	*map_create(int size)
{
	int		value;
	t_map	*tmp_map;

	if (!(tmp_map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	tmp_map->size = size;
	value = size * size + size + 1;
	tmp_map->map = ft_strnew(value);
	ft_bzero(tmp_map->map, size * size + size + 1);
	ft_memset(tmp_map->map, '.', size * size + size + 1);
	replace_chr(tmp_map->map, size);
	return (tmp_map);
}

void	delete_map(t_map *mapa)
{
	free(mapa);
	mapa = NULL;
}

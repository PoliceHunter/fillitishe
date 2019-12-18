/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:34:40 by tmyrcell          #+#    #+#             */
/*   Updated: 2019/12/12 14:35:30 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

void	clear_last(t_map *mapa, t_tetri *result, int x)
{
    int count_cur_name;

    count_cur_name = 0;
	while (mapa->map[x] != '\0')
	{
		if (mapa->map[x] == result->name)
        {
		    mapa->map[x] = '.';
		    count_cur_name += 1;
        }
		if (count_cur_name == 4)
		    break;
		x++;
	}
}

void	print_map(t_map *mapa)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < ((mapa->size * mapa->size) + mapa->size))
	{
		ft_putchar(mapa->map[j++]);
		i++;
	}
	ft_putendl("");
}

void    free_result(t_tetri *result)
{
    t_tetri *tmp;

    while (result != NULL)
    {
        tmp = result;
        result = result->next;
        free(tmp);
    }
    tmp = NULL;
}

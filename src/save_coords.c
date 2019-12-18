/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_coords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:56:00 by tmyrcell          #+#    #+#             */
/*   Updated: 2019/12/12 16:21:01 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

t_tetri		replace_coords(t_tetri *result, int min_x, int min_y)
{
	int		i;
	t_tetri	*current;

	current = result;
	while (current->next != NULL)
		current = current->next;
	if (min_x <= 0 && min_y <= 0)
		return (*result);
	i = 0;
	while (i < 8)
	{
		if ((min_x > 0) && (i % 2 == 0))
		{
			current->coords[i] = current->coords[i] - min_x;
			i++;
		}
		if ((min_y > 0) && (i % 2 != 0))
			current->coords[i] = current->coords[i] - min_y;
		i++;
	}
	i = 0;
	return (*result);
}

t_tetri		*find_min_coords(t_tetri *result)
{
	int		i;
	int		min_x;
	int		min_y;
	t_tetri	*current;

	current = result;
	while (current->next != NULL)
		current = current->next;
	i = 0;
	min_x = current->coords[i];
	min_y = current->coords[i + 1];
	while (i < 8)
	{
		if (min_x > current->coords[i])
			min_x = current->coords[i];
		if (min_y > current->coords[i + 1])
			min_y = current->coords[i + 1];
		i += 2;
	}
	replace_coords(current, min_x, min_y);
	return (result);
}

t_tetri		*create_node(void)
{
	t_tetri *tmp;

	tmp = (t_tetri *)malloc(sizeof(t_tetri));
	tmp->next = NULL;
	tmp->name = 'A';
	return (tmp);
}

t_tetri		push_back(t_tetri *result, char *line)
{
	t_tetri	*current;
	char	name;
	int		i;
	int		j;

	j = 0;
	i = 0;
	current = result;
	name = 'A';
	while ((current->next != NULL) && name++)
		current = current->next;
	current->next = malloc(sizeof(t_tetri));
	current->next->name = ++name;
	current->next->next = NULL;
	while (line[i] != '\0')
	{
		if (line[i] == '#')
		{
			current->next->coords[j] = i % 5;
			current->next->coords[j + 1] = i / 5;
			j += 2;
		}
		i++;
	}
	return (*result);
}

void		read_coords(char *line, t_tetri **result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*result == NULL)
	{
		*result = create_node();
		while (line[i] != '\0')
		{
			if (line[i] == '#')
			{
				(*result)->coords[j] = i % 5;
				(*result)->coords[j + 1] = i / 5;
				j += 2;
			}
			i++;
		}
	}
	else
		push_back(*result, line);
	find_min_coords(*result);
}

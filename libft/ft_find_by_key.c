/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_by_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:48:09 by tmyrcell          #+#    #+#             */
/*   Updated: 2019/11/04 15:48:52 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_find_by_key(t_rest_vector *vector, int key)
{
	unsigned int index;

	index = 0;
	if (vector == NULL)
		return (-1);
	if (vector->size == 0)
		return (-1);
	while (index != vector->size)
	{
		if (vector->data[index].key == key)
			return (index);
		++index;
	}
	return (-1);
}

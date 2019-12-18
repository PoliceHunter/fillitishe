/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:40:34 by tmyrcell          #+#    #+#             */
/*   Updated: 2019/11/04 15:41:35 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_push_back(t_rest_vector *vector, t_str_vec rest)
{
	t_str_vec *tmp;

	if (vector->size > vector->capacity)
	{
		vector->size *= MEMORY_REALLOC_COEF;
		tmp = malloc(sizeof(t_rest_vector) * vector->capacity);
		ft_memcpy(tmp, vector->data, vector->size * sizeof(t_rest_vector));
		free(vector->data);
		vector->data = tmp;
	}
	vector->data[vector->size] = rest;
	vector->size += 1;
}

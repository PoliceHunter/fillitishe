/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:39:35 by tmyrcell          #+#    #+#             */
/*   Updated: 2019/11/04 15:40:05 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rest_vector		*ft_create_vector(unsigned int capacity)
{
	t_rest_vector	*result;

	result = malloc(sizeof(t_rest_vector));
	result->size = 0;
	result->capacity = capacity;
	result->data = malloc(sizeof(t_str_vec) * result->capacity);
	return (result);
}

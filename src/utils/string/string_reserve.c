/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_reserve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:47:48 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/03 18:54:21 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/string.h"
#include <stdint.h>
#include <stdlib.h>

static char	*malloc_n_bzero(size_t n)
{
	char	*p;

	p = malloc(n);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, n);
	return (p);
}

static size_t	compute_new_capacity(size_t current, size_t min_capacity)
{
	size_t	new_capacity;

	if (min_capacity > (size_t)SIZE_MAX - 1)
		return (0);
	new_capacity = (current == 0) ? 1 : current;
	while (new_capacity < min_capacity)
	{
		if (new_capacity > ((size_t)SIZE_MAX - 1) / 2)
		{
			new_capacity = min_capacity;
			break ;
		}
		new_capacity *= 2;
	}
	return (new_capacity);
}

size_t	string_reserve(t_string *s, size_t min_capacity)
{
	size_t	new_capacity;
	char	*new_data;

	if (s == NULL)
		return (0);
	if (s->capacity >= min_capacity)
		return (s->capacity);
	new_capacity = compute_new_capacity(s->capacity, min_capacity);
	if (new_capacity == 0)
		return (0);
	if (new_capacity != s->capacity)
	{
		new_data = malloc_n_bzero(new_capacity + 1);
		if (new_data == NULL)
			return (0);
		if (s->data != NULL)
		{
			ft_memcpy(new_data, s->data, s->length);
			new_data[s->length] = '\0';
			free(s->data);
		}
		s->data = new_data;
		s->capacity = new_capacity;
	}
	return (s->capacity);
}

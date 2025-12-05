/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:32:40 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/03 18:53:59 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/string.h"

size_t	string_push(t_string *s, const char *src)
{
	size_t	src_len;
	size_t	new_length;

	if (s == NULL || src == NULL)
		return (0);
	src_len = ft_strlen(src);
	new_length = s->length + src_len;
	if (string_reserve(s, new_length) == 0)
		return (0);
	ft_memcpy(s->data + s->length, src, src_len);
	s->length = new_length;
	s->data[s->length] = '\0';
	return (src_len);
}

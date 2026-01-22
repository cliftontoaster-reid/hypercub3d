/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_parse_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/01/22 13:40:15 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

bool	table_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

char	*table_match_key(const char *line, const char *key)
{
	size_t	len;

	len = ft_strlen(key);
	if (ft_strncmp(line, key, len) == 0 && table_is_space(line[len]))
		return ((char *)line + len);
	return (NULL);
}

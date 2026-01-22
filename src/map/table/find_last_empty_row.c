/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last_empty_row.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:26:03 by mbores            #+#    #+#             */
/*   Updated: 2026/01/22 13:30:42 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map/table.h"

static bool	is_remaining_empty(const char *s)
{
	while (*s)
	{
		if (!ft_ciswhite((unsigned char)*s))
			return (false);
		s++;
	}
	return (true);
}

static bool	is_line_empty(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
	{
		if (!ft_ciswhite((unsigned char)s[i]))
			return (false);
		i++;
	}
	return (true);
}

static size_t	line_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

size_t	find_last_empty_row(const char *content)
{
	size_t	i;
	size_t	len;
	size_t	last_valid_pos;
	size_t	split;

	last_valid_pos = 0;
	if (!content)
		return (0);
	i = 0;
	while (content[i])
	{
		len = line_len(content + i);
		if (is_line_empty(content + i))
		{
			if (content[i + len] == '\n')
				split = i + len + 1;
			else
				split = i + len;
			if (!is_remaining_empty(content + split))
				last_valid_pos = split;
		}
		i += len;
		if (content[i] == '\n')
			i++;
	}
	return (last_valid_pos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_is_empty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:23:09 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/26 13:23:09 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/table.h"
#include "utils/string.h"

bool	line_is_empty(const char *s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (!table_is_space(s[i]))
			return (false);
		i++;
	}
	return (true);
}

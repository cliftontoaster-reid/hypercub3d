/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_ld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:32:11 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/22 13:32:12 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/image.h"
#include "libft.h"
#include "map/table.h"
#include <stdbool.h>

bool	ld(t_image **i, const char *p, t_table *t, bool *c)
{
	char	*p_trimmed;

	if (*c)
	{
		table_free(t);
		return (false);
	}
	p_trimmed = ft_strtrim(p, " \t");
	*i = image_from_file(t->mlx, p_trimmed);
	free(p_trimmed);
	if (!*i)
		return (false);
	*c = true;
	return (true);
}

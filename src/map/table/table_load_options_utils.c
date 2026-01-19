/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_load_options_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:46:25 by mbores            #+#    #+#             */
/*   Updated: 2026/01/19 16:27:04 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/colour.h"
#include "graphics/image.h"
#include "libft.h"
#include "map/table.h"

t_colour	parse_rbg(const char *str)
{
	t_colour	colour;
	char		**components;
	int			i;

	components = ft_split(str, ',');
	if (!components)
		return ((t_colour){0, 0, 0, 255});
	colour.r = (uint8_t)ft_atoi(components[0]);
	colour.g = (uint8_t)ft_atoi(components[1]);
	colour.b = (uint8_t)ft_atoi(components[2]);
	colour.a = 255;
	i = 0;
	while (components[i])
		free(components[i++]);
	free(components);
	return (colour);
}

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
	{
		// table_free(t);
		return (false);
	}
	*c = true;
	return (true);
}

bool	lrgb(t_colour *col, const char *s, t_table *t, bool *c)
{
	char	*s_trimmed;

	if (*c)
	{
		table_free(t);
		return (false);
	}
	s_trimmed = ft_strtrim(s, " \t");
	*col = parse_rbg(s_trimmed);
	free(s_trimmed);
	*c = true;
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_load_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:05:49 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/10 13:05:15 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/colour.h"
#include "graphics/image.h"
#include "libft.h"
#include "map/table.h"

#define cmp ft_strncmp

static t_colour	parse_rbg(const char *str)
{
	t_colour	colour;
	char		**components;

	components = ft_split(str, ',');
	if (!components)
		return ((t_colour){0, 0, 0, 255});
	colour.r = (uint8_t)ft_atoi(components[0]);
	colour.g = (uint8_t)ft_atoi(components[1]);
	colour.b = (uint8_t)ft_atoi(components[2]);
	colour.a = 255;
	for (int i = 0; components[i]; i++)
		free(components[i]);
	free(components);
	return (colour);
}

static bool	ld(t_image **i, const char *p, t_table *t, bool *c)
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
		table_free(t);
		return (false);
	}
	*c = true;
	return (true);
}

static bool	lrgb(t_colour *col, const char *s, t_table *t, bool *c)
{
	if (*c)
	{
		table_free(t);
		return (false);
	}
	*col = parse_rbg(ft_strtrim(s, " \t"));
	*c = true;
	return (true);
}

static bool	check_complete(bool cs[6])
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!cs[i])
			return (false);
		i++;
	}
	return (true);
}

bool	table_load_options(t_table *t, const char *options)
{
	char	**lines;
	int		i;
	char	*l;
	bool	cs[6];

	ft_bzero(cs, sizeof(cs));
	if (!t || !options)
		return (false);
	lines = ft_split(options, '\n');
	if (!lines)
		return (false);
	i = 0;
	while (lines[i])
	{
		l = lines[i];
		if (cmp(l, "NO ", 3) == 0 && !ld(&t->no_wall, l + 3, t, &cs[0]))
			return (false);
		else if (cmp(l, "SO ", 3) == 0 && !ld(&t->so_wall, l + 3, t, &cs[1]))
			return (false);
		else if (cmp(l, "WE ", 3) == 0 && !ld(&t->we_wall, l + 3, t, &cs[2]))
			return (false);
		else if (cmp(l, "EA ", 3) == 0 && !ld(&t->ea_wall, l + 3, t, &cs[3]))
			return (false);
		else if (cmp(l, "F ", 2) == 0 && !lrgb(&t->floor_col, l + 2, t, &cs[4]))
			return (false);
		else if (cmp(l, "C ", 2) == 0 && !lrgb(&t->ceil_col, l + 2, t, &cs[5]))
			return (false);
		free(l);
		i++;
	}
	free(lines);
	if (!check_complete(cs))
	{
		table_free(t);
		return (false);
	}
	return (true);
}

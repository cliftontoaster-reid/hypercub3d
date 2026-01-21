/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_load_options_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:46:25 by mbores            #+#    #+#             */
/*   Updated: 2026/01/21 14:35:29 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/colour.h"
#include "graphics/image.h"
#include "libft.h"
#include "map/table.h"
#include <stdbool.h>

static inline bool	is_valid_rgb(const char *s)
{
	size_t	i;
	uint8_t	k;

	i = 0;
	k = 0;
	if (ft_strfreq(s, ',') != 2)
		return (false);
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ',')
			return (false);
		if ((i == 0 || s[i - 1] == ',') && ft_isdigit(s[i]))
			k++;
		if (k > 3)
			return (false);
		i++;
	}
	if (k != 3)
		return (false);
	return (true);
}

static inline bool	fuckyouvscode(const char *s, int *out)
{
	char	**components;
	int		i;
	bool	ret;

	ret = true;
	components = ft_split(s, ',');
	if (!components)
	{
		free(components);
		return (false);
	}
	out[0] = ft_atoi(components[0]);
	out[1] = ft_atoi(components[1]);
	out[2] = ft_atoi(components[2]);
	if (out[0] < 0 || out[0] > 255)
		ret = false;
	if (out[1] < 0 || out[1] > 255)
		ret = false;
	if (out[2] < 0 || out[2] > 255)
		ret = false;
	i = 0;
	while (components[i])
		free(components[i++]);
	free(components);
	return (ret);
}

bool	parse_rbg(const char *str, t_colour *out)
{
	int	tmp[3];

	if (!is_valid_rgb(str))
		return (false);
	if (!fuckyouvscode(str, tmp))
		return (false);
	out->r = (uint8_t)tmp[0];
	out->g = (uint8_t)tmp[1];
	out->b = (uint8_t)tmp[2];
	out->a = 255;
	return (true);
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
		return (false);
	*c = true;
	return (true);
}

bool	lrgb(t_colour *col, const char *s, t_table *t, bool *c)
{
	char	*s_trimmed;

	(void)t;
	if (*c)
		return (false);
	s_trimmed = ft_strtrim(s, " \t");
	if (!parse_rbg(s_trimmed, col))
	{
		free(s_trimmed);
		return (false);
	}
	free(s_trimmed);
	*c = true;
	return (true);
}

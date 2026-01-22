/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_lrgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:33:55 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/22 13:36:44 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/colour.h"
#include "libft.h"
#include "map/table.h"
#include <stdbool.h>

static inline bool	is_valid_rgb(const char *s)
{
	size_t	i;
	uint8_t	k;

	if (ft_strfreq(s, ',') != 2)
		return (false);
	i = 0;
	k = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ',' && s[i] != ' ' && s[i] != '\t')
			return (false);
		if (ft_isdigit(s[i]) && (i == 0 || !ft_isdigit(s[i - 1])))
			k++;
		i++;
	}
	if (k != 3)
		return (false);
	return (true);
}

static void	free_lst(char **components)
{
	int	i;

	i = 0;
	while (components[i])
		free(components[i++]);
	free(components);
}

static inline bool	fuckyouvscode(const char *s, int *out)
{
	char	**components;
	int		i;
	bool	ret;
	char	*t[3];

	ret = true;
	components = ft_split(s, ',');
	if (!components)
	{
		free(components);
		return (false);
	}
	i = 0;
	while (i < 3)
	{
		t[i] = ft_strtrim(components[i], " \t");
		out[i] = ft_atoi(t[i]);
		free(t[i]);
		if (out[i] < 0 || out[i] > 255)
			ret = false;
		i++;
	}
	free_lst(components);
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

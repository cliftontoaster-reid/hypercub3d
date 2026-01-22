/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_parse_option_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:00:00 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/22 13:00:00 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/colour.h"
#include "graphics/image.h"
#include "libft.h"
#include "map/table.h"
#include "utils/error.h"

bool	table_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

static char	*match_key(const char *line, const char *key)
{
	size_t	len;

	len = ft_strlen(key);
	if (ft_strncmp(line, key, len) == 0 && table_is_space(line[len]))
		return ((char *)line + len);
	return (NULL);
}

static int	process_tex_opt(t_table *t, char *l, t_image **i, bool *b, char *k)
{
	char	*val;

	val = match_key(l, k);
	if (!val)
		return (0);
	if (*b)
	{
		err_print_option_error(l, "Duplicate texture");
		return (-1);
	}
	if (!ld(i, val, t, b))
	{
		err_print_option_error(l, "Failed to load texture");
		return (-1);
	}
	return (1);
}

static int	process_col_opt(t_table *t, char *l, t_colour *c, bool *b, char *k)
{
	char	*val;

	val = match_key(l, k);
	if (!val)
		return (0);
	if (*b)
	{
		err_print_option_error(l, "Duplicate color");
		return (-1);
	}
	if (!lrgb(c, val, t, b))
	{
		err_print_option_error(l, "Invalid RGB format");
		return (-1);
	}
	return (1);
}

bool	table_parse_option_line(t_table *t, char *l, t_opt_ctx *c)
{
	int	r;

	if ((r = process_tex_opt(t, l, &t->no_wall, &c->no, "NO")) != 0)
		return (r == 1);
	if ((r = process_tex_opt(t, l, &t->so_wall, &c->so, "SO")) != 0)
		return (r == 1);
	if ((r = process_tex_opt(t, l, &t->we_wall, &c->we, "WE")) != 0)
		return (r == 1);
	if ((r = process_tex_opt(t, l, &t->ea_wall, &c->ea, "EA")) != 0)
		return (r == 1);
	if ((r = process_col_opt(t, l, &t->floor_col, &c->f, "F")) != 0)
		return (r == 1);
	if ((r = process_col_opt(t, l, &t->ceil_col, &c->c, "C")) != 0)
		return (r == 1);
	err_print_option_error(l, "Unknown option");
	return (false);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_parse_tex_option.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:40:00 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/22 13:44:11 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/image.h"
#include "map/table.h"
#include "utils/error.h"
#include <stdbool.h>

char		*table_match_key(const char *line, const char *key);

static int	try_so(t_table *t, char *l, t_opt_ctx *c);
static int	try_we(t_table *t, char *l, t_opt_ctx *c);
static int	try_ea(t_table *t, char *l, t_opt_ctx *c);

static int	try_no(t_table *t, char *l, t_opt_ctx *c)
{
	char	*val;

	val = table_match_key(l, "NO");
	if (!val)
		return (try_so(t, l, c));
	if (c->no)
		return (err_print_option_error(l, "Duplicate texture"), -1);
	if (!ld(&t->no_wall, val, t, &c->no))
		return (err_print_option_error(l, "Failed to load texture"), -1);
	return (1);
}

static int	try_so(t_table *t, char *l, t_opt_ctx *c)
{
	char	*val;

	val = table_match_key(l, "SO");
	if (!val)
		return (try_we(t, l, c));
	if (c->so)
		return (err_print_option_error(l, "Duplicate texture"), -1);
	if (!ld(&t->so_wall, val, t, &c->so))
		return (err_print_option_error(l, "Failed to load texture"), -1);
	return (1);
}

static int	try_we(t_table *t, char *l, t_opt_ctx *c)
{
	char	*val;

	val = table_match_key(l, "WE");
	if (!val)
		return (try_ea(t, l, c));
	if (c->we)
		return (err_print_option_error(l, "Duplicate texture"), -1);
	if (!ld(&t->we_wall, val, t, &c->we))
		return (err_print_option_error(l, "Failed to load texture"), -1);
	return (1);
}

static int	try_ea(t_table *t, char *l, t_opt_ctx *c)
{
	char	*val;

	val = table_match_key(l, "EA");
	if (!val)
		return (0);
	if (c->ea)
		return (err_print_option_error(l, "Duplicate texture"), -1);
	if (!ld(&t->ea_wall, val, t, &c->ea))
		return (err_print_option_error(l, "Failed to load texture"), -1);
	return (1);
}

int	table_parse_tex_option(t_table *t, char *l, t_opt_ctx *c)
{
	return (try_no(t, l, c));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_parse_col_option.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:40:00 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/22 13:40:00 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/colour.h"
#include "map/table.h"
#include "utils/error.h"
#include <stdbool.h>

char	*table_match_key(const char *line, const char *key);

int	table_parse_col_option(t_table *t, char *l, t_opt_ctx *c)
{
	char	*val;

	val = table_match_key(l, "F");
	if (val)
	{
		if (c->f)
			return (err_print_option_error(l, "Duplicate color"), -1);
		if (!lrgb(&t->floor_col, val, t, &c->f))
			return (err_print_option_error(l, "Invalid RGB format"), -1);
		return (1);
	}
	val = table_match_key(l, "C");
	if (val)
	{
		if (c->c)
			return (err_print_option_error(l, "Duplicate color"), -1);
		if (!lrgb(&t->ceil_col, val, t, &c->c))
			return (err_print_option_error(l, "Invalid RGB format"), -1);
		return (1);
	}
	return (0);
}

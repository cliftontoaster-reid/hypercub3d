/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_parse_option_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:00:00 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/22 13:40:11 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/table.h"
#include "utils/error.h"
#include <stdbool.h>

int		table_parse_tex_option(t_table *t, char *l, t_opt_ctx *c);
int		table_parse_col_option(t_table *t, char *l, t_opt_ctx *c);

bool	table_parse_option_line(t_table *t, char *l, t_opt_ctx *c)
{
	int	r;

	r = table_parse_tex_option(t, l, c);
	if (r != 0)
		return (r == 1);
	r = table_parse_col_option(t, l, c);
	if (r != 0)
		return (r == 1);
	err_print_option_error(l, "Unknown option");
	return (false);
}

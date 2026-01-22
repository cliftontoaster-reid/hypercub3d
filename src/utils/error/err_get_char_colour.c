/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_get_char_colour.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:15:00 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/22 11:10:12 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/error.h"

const char	*err_get_char_colour(char c)
{
	if (c == TABLE_CELL_WALL)
		return (ERR_COL_BLUE);
	if (c == TABLE_CELL_FLOOR)
		return (ERR_COL_GREY);
	if (c == TABLE_CELL_PLAYER_N || c == TABLE_CELL_PLAYER_S
		|| c == TABLE_CELL_PLAYER_E || c == TABLE_CELL_PLAYER_W)
		return (ERR_COL_GREEN);
	if (c == TABLE_CELL_EMPTY)
		return (ERR_COL_RESET);
	return (ERR_COL_RED);
}

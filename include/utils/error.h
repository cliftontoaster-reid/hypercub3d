/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:44:20 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/22 10:57:41 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "map/table.h"
#include "utils/vec.h"
#include <stdio.h>

// ANSI Color Codes for easy reference
#define ERR_COL_RED "\033[1;31m"
#define ERR_COL_GREEN "\033[1;32m"
#define ERR_COL_YELLOW "\033[1;33m"
#define ERR_COL_BLUE "\033[1;34m"
#define ERR_COL_GREY "\033[1;90m"
#define ERR_COL_RESET "\033[0m"
#define ERR_BG_RED "\033[41m"

/// @brief Get the ANSI color code associated with a specific map character.
/// @param c The character to check (e.g., '1', '0', 'N').
/// @return A string containing the ANSI color code.
const char *err_get_char_colour(char c);

/// @brief Print a focused, zoomed-in square around a specific position.
/// Good for large maps where printing the whole thing is too noisy.
/// @param map The map structure.
/// @param pos The center position of the view.
/// @param radius The number of cells to show in each direction (e.g., 5).
/// @param msg An optional custom message.
void err_print_context(const t_table *map, t_vec2i pos, int radius,
											 const char *msg);

/// @brief Print an error related to parsing a specific option line.
/// @param line The full line content that caused the error.
/// @param msg The specific reason (e.g., "Duplicate option", "Invalid RGB").
void err_print_option_error(const char *line, const char *msg);

/// @brief Standard error message printer.
/// @param header The context (e.g., "Map Error").
/// @param msg The detail (e.g., "File not found").
void err_msg(const char *header, const char *msg);

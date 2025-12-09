/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntaxotron.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:44:45 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/08 16:10:22 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "map/table.h"
#include <stdbool.h>
#include <sys/types.h>

#define SYN_ALLOWED " \n01NSEW"

#define SYN_ERR_INVALID_CHAR "Invalid character in map."
#define SYN_ERR_MULTIPLE_PLAYERS "Multiple player start positions."
#define SYN_ERR_NO_PLAYER "No player start position defined."
#define SYN_ERR_MAP_NOT_CLOSED "Map is not closed/surrounded by walls."
#define SYN_ERR_EMPTY_MAP "Map is empty."
#define SYN_ERR_MISSING_WALL_TEXTURES "Missing wall textures."
#define SYN_ERR_INVALID_WALL_TEXTURE "Invalid wall texture path."
#define SYN_ERR_CANNOT_OPEN_WALL_TEXTURE "Cannot open wall texture file."
#define SYN_ERR_CANNOT_LOAD_WALL_TEXTURE "Cannot load wall texture."
#define SYN_ERR_CANNOT_OPEN_MAP_FILE "Cannot open map file."
#define SYN_ERR_MEMORY_ALLOCATION "Memory allocation failed."
#define SYN_ERR_UNEXPECTED_EOF "Unexpected end of file."
#define SYN_ERR_NO_EMPTY_ROWS "No empty lines are in the map."

/// @brief Scan the map string for illegal characters
/// @param str The map string to scan
/// @return true if the string contains only allowed characters, false otherwise
ssize_t	syn_scanstr(const char *str);

/// @brief Check if the character is part of the allowed syntax characters
/// @param c The character to check
/// @return true if the character is valid, false otherwise
bool	syn_validchar(char c);

/// @brief Validate that the map is not using American layout
///
/// By non American layout, we mean that the map should not have an open wall
/// to the void of space,
///	and therefore is safe to walk inside the map boundaries.
///
/// @param map_str The map string to validate
/// @return true if the map is valid, false otherwise
bool	syn_validate_unamerican(t_table *map);

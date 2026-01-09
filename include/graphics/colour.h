/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:40:50 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/09 16:08:20 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>

/**
 * @enum e_endianess
 * @brief Specifies the byte order for pixel data.
 */
typedef enum e_endianess
{
	ENDIAN_LITTLE = 0,
	ENDIAN_BIG = 1
}						t_endianess;

/**
 * @struct s_colour
 * @brief Represents a colour with Red, Green, Blue, and Alpha components.
 */
typedef struct s_colour
{
	uint8_t				r;
	uint8_t				g;
	uint8_t				b;
	uint8_t				a;
}						t_colour;

/**
 * @brief Creates a t_colour struct with RGBA values.
 * @param r Red component (0-255).
 * @param g Green component (0-255).
 * @param b Blue component (0-255).
 * @param a Alpha component (0-255).
 * @return A t_colour struct with the specified values.
 */
static inline t_colour	rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return ((t_colour){r, g, b, a});
}

/**
 * @brief Creates a t_colour struct with RGB values and a default alpha of 255.
 * @param r Red component (0-255).
 * @param g Green component (0-255).
 * @param b Blue component (0-255).
 * @return A t_colour struct with the specified values and full opacity.
 */
static inline t_colour	rgb(uint8_t r, uint8_t g, uint8_t b)
{
	return ((t_colour){r, g, b, 255});
}

/**
 * @brief Converts a t_colour struct to a 32-bit unsigned integer.
 * The byte order depends on the endianness.
 * @param colour The t_colour struct to convert.
 * @param endianess The endianness of the system.
 * @return The colour as a 32-bit integer.
 */
static inline uint32_t	colour_to_uint(t_colour colour, t_endianess endianess)
{
	if (endianess != ENDIAN_LITTLE)
		return ((uint32_t)(colour.b << 16 | colour.g << 8 | colour.r));
	else
		return ((uint32_t)(colour.r << 16 | colour.g << 8 | colour.b));
}

/**
 * @brief Converts a 32-bit unsigned integer to a t_colour struct.
 * The byte order depends on the endianness.
 * @param value The 32-bit integer to convert.
 * @param endianess The endianness of the system.
 * @return The colour as a t_colour struct.
 */
static inline t_colour	uint_to_colour(uint32_t value, t_endianess endianess)
{
	if (endianess == ENDIAN_LITTLE)
		return ((t_colour){(uint8_t)(value & 0x000000FF),
			(uint8_t)((value & 0x0000FF00) >> 8),
			(uint8_t)((value & 0x00FF0000) >> 16),
			(uint8_t)((value & 0xFF000000) >> 24)});
	else
		return ((t_colour){(uint8_t)((value & 0xFF000000) >> 24),
			(uint8_t)((value & 0x00FF0000) >> 16),
			(uint8_t)((value & 0x0000FF00) >> 8),
			(uint8_t)(value & 0x000000FF)});
}

/**
 * @brief A shorthand function to convert a t_colour struct to an integer.
 * Assumes little-endian byte order.
 * @param colour The t_colour struct to convert.
 * @return The colour as an integer.
 */
static inline int	c(t_colour colour)
{
	return ((int)colour_to_uint(colour, ENDIAN_LITTLE));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:40:50 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/21 14:49:35 by mbores           ###   ########.fr       */
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
t_colour	rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

/**
 * @brief Creates a t_colour struct with RGB values and a default alpha of 255.
 * @param r Red component (0-255).
 * @param g Green component (0-255).
 * @param b Blue component (0-255).
 * @return A t_colour struct with the specified values and full opacity.
 */
t_colour	rgb(uint8_t r, uint8_t g, uint8_t b);

/**
 * @brief Converts a t_colour struct to a 32-bit unsigned integer.
 * The byte order depends on the endianness.
 * @param colour The t_colour struct to convert.
 * @param endianess The endianness of the system.
 * @return The colour as a 32-bit integer.
 */
uint32_t	colour_to_uint(t_colour colour, t_endianess endianess);

/**
 * @brief Converts a 32-bit unsigned integer to a t_colour struct.
 * The byte order depends on the endianness.
 * @param value The 32-bit integer to convert.
 * @param endianess The endianness of the system.
 * @return The colour as a t_colour struct.
 */
t_colour	uint_to_colour(uint32_t value, t_endianess endianess);

/**
 * @brief A shorthand function to convert a t_colour struct to an integer.
 * Assumes little-endian byte order.
 * @param colour The t_colour struct to convert.
 * @return The colour as an integer.
 */
int			c(t_colour colour);

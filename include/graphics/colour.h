/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:40:50 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/05 11:22:21 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "graphics/image.h"
#include <stdint.h>

typedef struct s_colour
{
	uint8_t				r;
	uint8_t				g;
	uint8_t				b;
	uint8_t				a;
}						t_colour;

static inline t_colour	rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return ((t_colour){r, g, b, a});
}

static inline t_colour	rgb(uint8_t r, uint8_t g, uint8_t b)
{
	return ((t_colour){r, g, b, 255});
}

static inline uint32_t	colour_to_uint(t_colour colour, t_endianess endianess)
{
	if (endianess != ENDIAN_LITTLE)
		return ((uint32_t)(colour.b << 16 | colour.g << 8 | colour.r));
	else
		return ((uint32_t)(colour.r << 16 | colour.g << 8 | colour.b));
}

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

static inline int	c(t_colour colour)
{
	return ((int)colour_to_uint(colour, ENDIAN_LITTLE));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:43:02 by mbores            #+#    #+#             */
/*   Updated: 2026/01/21 14:45:14 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/colour.h"

t_colour	rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return ((t_colour){r, g, b, a});
}

t_colour	rgb(uint8_t r, uint8_t g, uint8_t b)
{
	return ((t_colour){r, g, b, 255});
}

uint32_t	colour_to_uint(t_colour colour, t_endianess endianess)
{
	if (endianess != ENDIAN_LITTLE)
		return ((uint32_t)(colour.b << 16 | colour.g << 8 | colour.r));
	else
		return ((uint32_t)(colour.r << 16 | colour.g << 8 | colour.b));
}

t_colour	uint_to_colour(uint32_t value, t_endianess endianess)
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

int	c(t_colour colour)
{
	return ((int)colour_to_uint(colour, ENDIAN_LITTLE));
}

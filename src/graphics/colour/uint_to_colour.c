/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_to_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:47:33 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/03 18:48:18 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/colour.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_to_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:47:15 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/03 18:48:03 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/colour.h"

uint32_t	colour_to_uint(t_colour colour, t_endianess endianess)
{
	if (endianess == ENDIAN_LITTLE)
		return ((uint32_t)(colour.a << 24 | colour.b << 16 | colour.g << 8 | colour.r));
	else
		return ((uint32_t)(colour.r << 24 | colour.g << 16 | colour.b << 8 | colour.a));
}

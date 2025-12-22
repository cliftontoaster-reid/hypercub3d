/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:40:50 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/19 15:27:00 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "graphics/image.h"
#include <stdint.h>

typedef struct s_colour
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
}			t_colour;

t_colour	rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
t_colour	rgb(uint8_t r, uint8_t g, uint8_t b);
uint32_t	colour_to_uint(t_colour colour, t_endianess endianess);
t_colour	uint_to_colour(uint32_t value, t_endianess endianess);
int			c(t_colour colour);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:25:41 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/19 15:26:53 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/colour.h"

inline int	c(t_colour colour)
{
	return (int)colour_to_uint(colour, ENDIAN_LITTLE);
}

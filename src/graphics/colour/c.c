/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:25:41 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/04 15:26:50 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/colour.h"

inline int	c(t_colour colour, t_endianess endianess)
{
	return (int)colour_to_uint(colour, endianess);
}

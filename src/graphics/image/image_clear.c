/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:48:42 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/09 15:49:49 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/colour.h"
#include "graphics/image.h"

void	image_clear(t_image *img, t_colour colour)
{
	int	x;
	int	y;
	int	col;

	col = c(colour);
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			image_put_pixel(img, x, y, col);
			x++;
		}
		y++;
	}
}

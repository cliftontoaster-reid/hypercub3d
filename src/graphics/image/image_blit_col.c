/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_blit_col.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:56:30 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/13 15:17:11 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/image.h"
#include "utils/vec.h"

static void	blit_column_cropped(t_col_blit *c)
{
	int		dest_y;
	float	src_y_float;
	int		src_y;
	int		color;

	dest_y = c->range.x;
	while (dest_y < c->range.x + c->range.y)
	{
		src_y_float = ((float)(dest_y - c->range.x) / (float)c->range.y)
			* c->src_crop_height + c->src_crop_start;
		src_y = (int)src_y_float;
		if (c->src_pos.x >= 0 && c->src_pos.x < c->src->width
			&& src_y >= 0 && src_y < c->src->height)
		{
			color = image_get_pixel(c->src, c->src_pos.x, src_y);
			image_put_pixel(c->dest, c->src_pos.y, dest_y, color);
		}
		dest_y++;
	}
}

// scale is 0 to 1 where 1 is full size and 0 is no size
// must use nearest neighbor scaling
// range.x = dest start_y, range.y = dest height
// src_crop_start and src_crop_height define
// 		the portion of src texture to sample
static bool	compute_column_blit(t_col_blit *c, float scale)
{
	float	rendered_height;

	rendered_height = scale * (float)c->src->height;
	if (rendered_height >= (float)c->dest->height)
	{
		c->range.x = 0;
		c->range.y = c->dest->height;
		c->src_crop_height = (float)c->src->height
			* (float)c->dest->height / rendered_height;
		c->src_crop_start = ((float)c->src->height
				- c->src_crop_height) / 2.0f;
	}
	else
	{
		c->range.y = (int)rendered_height;
		if (c->range.y <= 0)
			return (false);
		c->range.x = (c->dest->height - c->range.y) / 2;
		c->src_crop_height = (float)c->src->height;
		c->src_crop_start = 0.0f;
	}
	return (true);
}

void	image_blit_col(t_image *dest, t_image *src, t_vec2i x, float scale)
{
	t_col_blit	c;

	if (!dest || !src || !(scale > 0.0f))
		return ;
	c.dest = dest;
	c.src = src;
	c.src_pos = vec2i_new(x.x, x.y);
	if (!compute_column_blit(&c, scale))
		return ;
	blit_column_cropped(&c);
}

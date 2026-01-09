/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_blit_col.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:56:30 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/09 16:19:53 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/image.h"
#include "utils/vec.h"

// scale is 0 to 1 where 1 is full size and 0 is no size
// must use nearest neighbor scaling
// range.x = dest start_y, range.y = dest height
// src_crop_start and src_crop_height define the portion of src texture to sample
static void	blit_column_cropped(t_image *dest, t_image *src, t_vec2i src_pos,
		t_vec2i range, float src_crop_start, float src_crop_height)
{
	int		dest_y;
	float	src_y_float;
	int		src_y;
	int		color;

	dest_y = range.x;
	while (dest_y < range.x + range.y)
	{
		src_y_float = ((float)(dest_y - range.x) / (float)range.y)
			* src_crop_height + src_crop_start;
		src_y = (int)src_y_float;
		if (src_pos.x >= 0 && src_pos.x < src->width && src_y >= 0
			&& src_y < src->height)
		{
			color = image_get_pixel(src, src_pos.x, src_y);
			image_put_pixel(dest, src_pos.y, dest_y, color);
		}
		dest_y++;
	}
}

void	image_blit_col(t_image *dest, t_image *src, t_vec2i x, float scale)
{
	t_vec2i	src_pos;
	float	rendered_height;
	int		dest_height;
	int		start_y;
	float	src_crop_start;
	float	src_crop_height;

	if (!(scale > 0.0f))
		return ;
	src_pos = vec2i_new(x.x, x.y);
	/* Calculate how tall the wall "wants" to be based on scale */
	rendered_height = scale * (float)src->height;
	if (rendered_height >= (float)dest->height)
	{
		/* Wall is taller than screen: fill screen and crop texture */
		dest_height = dest->height;
		src_crop_height = (float)src->height * (float)dest->height
			/ rendered_height;
		src_crop_start = ((float)src->height - src_crop_height) / 2.0f;
		start_y = 0;
	}
	else
	{
		/* Wall is smaller than screen: render at scaled size, centered */
		dest_height = (int)rendered_height;
		if (dest_height <= 0)
			return ;
		src_crop_height = (float)src->height;
		src_crop_start = 0.0f;
		start_y = (dest->height - dest_height) / 2;
	}
	blit_column_cropped(dest, src, src_pos, vec2i_new(start_y, dest_height),
		src_crop_start, src_crop_height);
}

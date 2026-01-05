/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:54:47 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/05 11:21:32 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils/vec.h"
#include <stddef.h>

typedef struct s_pos
{
	t_vec2i	src_pos;
	t_vec2i	dest_pos;

	t_vec2i	src_size;
	t_vec2i	size;
}			t_pos;

typedef enum e_endianess
{
	ENDIAN_LITTLE = 0,
	ENDIAN_BIG = 1
}			t_endianess;

typedef struct s_image
{
	int		width;
	int		height;

	void	*mlx_ptr;
	void	*img_ptr;

	char	*addr;

	/// @brief The number of bits per pixel
	int		bpp;
	/// @brief The number of bytes in a single row of the image
	int		lln;
	/// @brief The endianess of the image data
	int		endian;
}			t_image;

t_image		*image_new(void *mlx_ptr, int width, int height);
t_image		*image_from_file(void *mlx_ptr, const char *filepath);
void		image_free(t_image *img);
void		image_clear(t_image *img, int color);
void		image_blit(t_image *dest, t_image *src, t_pos *pos);
/* Pixel operations */
void		image_put_pixel(t_image *img, int x, int y, int color);
int			image_get_pixel(t_image *img, int x, int y);
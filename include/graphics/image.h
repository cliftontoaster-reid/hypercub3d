/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:54:47 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/03 16:20:26 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stddef.h>

typedef enum e_endianess
{
	ENDIAN_LITTLE = 0,
	ENDIAN_BIG = 1
}				t_endianess;

typedef struct s_image
{
	size_t		width;
	size_t		height;

	void		*mlx_ptr;
	void		*img_ptr;
	void		*data_ptr;

	/// @brief The number of bits per pixel
	int			bpp;
	/// @brief The number of bytes in a single row of the image
	int			lln;
	/// @brief The endianess of the image data
	t_endianess	endian;
}				t_image;

t_image			*image_new(void *mlx_ptr, size_t width, size_t height);
t_image			*image_from_file(void *mlx_ptr, const char *filepath);
void			image_free(t_image *img);

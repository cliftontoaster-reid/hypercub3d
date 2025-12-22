/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:54:47 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/22 15:14:19 by mbores           ###   ########.fr       */
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
	int			width;
	int			height;

	void		*mlx_ptr;
	void		*img_ptr;

	char		*addr;

	/// @brief The number of bits per pixel
	int			bpp;
	/// @brief The number of bytes in a single row of the image
	int			lln;
	/// @brief The endianess of the image data
	int			endian;
}				t_image;

t_image			*image_new(void *mlx_ptr, int width, int height);
t_image			*image_from_file(void *mlx_ptr, const char *filepath);
void			image_free(t_image *img);

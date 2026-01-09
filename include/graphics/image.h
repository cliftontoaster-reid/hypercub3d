/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:54:47 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/09 16:07:21 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "graphics/colour.h"
#include "utils/vec.h"
#include <stddef.h>

/**
 * @struct s_pos
 * @brief Defines source and destination positions and sizes for image blitting.
 */
typedef struct s_pos
{
	t_vec2i	src_pos;
	t_vec2i	dest_pos;

	t_vec2i	src_size;
	t_vec2i	size;
}			t_pos;

/**
 * @struct s_image
 * @brief Represents an image that can be manipulated and displayed.
 *
 * This structure holds image dimensions, pointers to the MLX image and its
 * raw pixel data, and information about the image format like bits per pixel,
 * line length, and endianness.
 */
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

/**
 * @brief Creates a new, empty image.
 * @param mlx_ptr Pointer to the MinilibX instance.
 * @param width The width of the new image.
 * @param height The height of the new image.
 * @return A pointer to the new image, or NULL on failure.
 */
t_image		*image_new(void *mlx_ptr, int width, int height);

/**
 * @brief Creates an image from an XPM file.
 * @param mlx_ptr Pointer to the MinilibX instance.
 * @param filepath Path to the XPM file.
 * @return A pointer to the new image, or NULL on failure.
 */
t_image		*image_from_file(void *mlx_ptr, const char *filepath);

/**
 * @brief Frees the memory associated with an image.
 * @param img The image to free.
 */
void		image_free(t_image *img);

/**
 * @brief Clears an image by filling it with a single color.
 * @param img The image to clear.
 * @param colour The color to fill the image with.
 */
void		image_clear(t_image *img, t_colour colour);

/**
 * @brief Copies a rectangular area from one image to another.
 * @param dest The destination image.
 * @param src The source image.
 * @param pos Defines the source and destination rectangles.
 */
void		image_blit(t_image *dest, t_image *src, t_pos *pos);

void		image_blit_col(t_image *dest, t_image *src, t_vec2i x, float scale);

/* Pixel operations */
/**
 * @brief Puts a pixel of a specified color at a given coordinate in an image.
 * @param img The image to modify.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param color The color of the pixel.
 */
void		image_put_pixel(t_image *img, int x, int y, int color);

/**
 * @brief Gets the color of a pixel at a given coordinate in an image.
 * @param img The image to read from.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @return The color of the pixel.
 */
int			image_get_pixel(t_image *img, int x, int y);
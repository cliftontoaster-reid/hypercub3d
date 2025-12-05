/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:14:45 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/03 16:14:59 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/image.h"
#include "mlx.h"
#include <stdlib.h>

t_image	*image_new(void *mlx_ptr, size_t width, size_t height)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	if (img == NULL)
		return (NULL);
	img->mlx_ptr = mlx_ptr;
	img->width = width;
	img->height = height;
	img->img_ptr = mlx_new_image(mlx_ptr, width, height);
	if (img->img_ptr == NULL)
	{
		free(img);
		return (NULL);
	}
	img->data_ptr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->lln, NULL);
	return (img);
}

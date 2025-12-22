/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:14:45 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/22 14:13:56 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/image.h"
#include "mlx.h"
#include <stdlib.h>

t_image	*image_new(void *mlx_ptr, int width, int height)
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
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->lln, &img->endian);
	return (img);
}

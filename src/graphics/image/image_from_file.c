/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_from_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:24:57 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/22 15:15:10 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/image.h"
#include "mlx.h"
#include <stdlib.h>

t_image	*image_from_file(void *mlx_ptr, const char *filepath)
{
	t_image	*img;
	int		endian;

	img = malloc(sizeof(t_image));
	if (img == NULL)
		return (NULL);
	img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, (char *)filepath,
			(int *)&img->width, (int *)&img->height);
	if (img->img_ptr == NULL)
	{
		free(img);
		return (NULL);
	}
	img->mlx_ptr = mlx_ptr;
	endian = 0;
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->lln,
			&endian);
	if (endian == 0)
		img->endian = ENDIAN_LITTLE;
	else
		img->endian = ENDIAN_BIG;
	return (img);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:14:24 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/03 16:14:43 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/image.h"
#include "mlx.h"
#include <stdlib.h>

void	image_free(t_image *img)
{
	if (img == NULL)
		return ;
	if (img->img_ptr != NULL && img->mlx_ptr != NULL)
		mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	free(img);
}

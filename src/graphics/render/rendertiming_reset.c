/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendertiming_reset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:55:31 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/13 15:44:55 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/render.h"

void	rendertiming_reset(t_rendertiming *timing)
{
	timing->per_ray_avg = 0;
	timing->per_ray_max = 0;
	timing->per_ray_min = 0;
	timing->all_rays = 0;
	timing->image_render = 0;
	timing->samples = 0;
	timing->next_ray_index = 0;
}

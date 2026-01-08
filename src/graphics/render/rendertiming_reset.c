/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendertiming_reset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:55:31 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/07 11:29:37 by lfiorell         ###   ########.fr       */
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

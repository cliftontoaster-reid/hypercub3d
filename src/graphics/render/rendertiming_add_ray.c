/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendertiming_add_ray.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:55:14 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/06 15:21:30 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/render.h"

void	rendertiming_add_ray(t_rendertiming *t, double time)
{
	if (t->next_ray_index < RAYCAST_MAX_RAYS)
	{
		t->ray_times[t->next_ray_index] = time;
		t->next_ray_index++;
		t->samples++;
		t->all_rays += time;
		if (time > t->per_ray_max)
			t->per_ray_max = time;
		if (time < t->per_ray_min || t->per_ray_min == 0)
			t->per_ray_min = time;
		t->per_ray_avg = t->all_rays / t->samples;
	}
}

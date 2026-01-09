/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_hit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:47:12 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/09 16:10:42 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/raycast.h"
#include <math.h>

void	calculate_hit(t_raycast *ray, t_rayhit *hit, t_rayside side)
{
	if (side == RAY_SIDE_EAST || side == RAY_SIDE_WEST)
	{
		if (ray->fisheye_correction)
			hit->dist = (ray->side_dist.x - ray->delta_dist.x);
		else
			hit->dist = (ray->map_pos.x - ray->player_pos.x + (1 - ray->step.x)
					/ 2) / ray->ray_dir.x;
		hit->hit_pos = ray->player_pos.y + hit->dist * ray->ray_dir.y;
	}
	else
	{
		if (ray->fisheye_correction)
			hit->dist = (ray->side_dist.y - ray->delta_dist.y);
		else
			hit->dist = (ray->map_pos.y - ray->player_pos.y + (1 - ray->step.y)
					/ 2) / ray->ray_dir.y;
		hit->hit_pos = ray->player_pos.x + hit->dist * ray->ray_dir.x;
	}
	/* Guard against NaN/Inf produced by invalid ray directions or math */
	if (!isfinite(hit->dist) || !isfinite(hit->hit_pos))
	{
		hit->hit_side = RAY_SIDE_NONE;
		hit->hit_map = ray->map_pos;
		return ;
	}
	hit->hit_pos -= (int)hit->hit_pos;
	if (side == RAY_SIDE_EAST || side == RAY_SIDE_WEST)
		set_side_communist(ray, side, hit);
	else
		set_side_capitalist(ray, side, hit);
	hit->hit_map = ray->map_pos;
}

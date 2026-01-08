/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:47:23 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/06 14:47:49 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/raycast.h"

void	perform_dda(t_raycast *ray, bool **map, t_rayside *side)
{
	while (ray->hit == false)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map_pos.x += ray->step.x;
			*side = RAY_SIDE_EAST;
			if (ray->step.x < 0)
				*side = RAY_SIDE_WEST;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map_pos.y += ray->step.y;
			*side = RAY_SIDE_SOUTH;
			if (ray->step.y < 0)
				*side = RAY_SIDE_NORTH;
		}
		if (map[ray->map_pos.y][ray->map_pos.x])
			ray->hit = true;
	}
}

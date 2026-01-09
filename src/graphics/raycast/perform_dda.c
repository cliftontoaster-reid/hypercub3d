/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:47:23 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/08 15:23:53 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/raycast.h"

void	perform_dda(t_raycast *ray, char **map, t_rayside *side)
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
		if (ray->map_pos.x < 0 || ray->map_pos.x >= (int)ray->map_table->width
			|| ray->map_pos.y < 0
			|| ray->map_pos.y >= (int)ray->map_table->height)
			ray->hit = true;
		else if (map[ray->map_pos.y][ray->map_pos.x] == '1')
			ray->hit = true;
	}
}

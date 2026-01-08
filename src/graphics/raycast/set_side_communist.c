/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_side_communist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:47:28 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/06 14:47:55 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/raycast.h"

void	set_side_communist(t_raycast *ray, t_rayside side, t_rayhit *hit)
{
	if (side == RAY_SIDE_EAST)
	{
		if (ray->ray_dir.x > 0)
			hit->hit_side = RAY_SIDE_WEST;
		else
			hit->hit_side = RAY_SIDE_EAST;
	}
	else if (side == RAY_SIDE_WEST)
	{
		if (ray->ray_dir.x < 0)
			hit->hit_side = RAY_SIDE_EAST;
		else
			hit->hit_side = RAY_SIDE_WEST;
	}
}

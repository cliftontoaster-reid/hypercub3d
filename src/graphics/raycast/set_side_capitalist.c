/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_side_capitalist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:47:37 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/06 14:47:52 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/raycast.h"

void	set_side_capitalist(t_raycast *ray, t_rayside side, t_rayhit *hit)
{
	if (side == RAY_SIDE_SOUTH)
	{
		if (ray->ray_dir.y > 0)
			hit->hit_side = RAY_SIDE_NORTH;
		else
			hit->hit_side = RAY_SIDE_SOUTH;
	}
	else
	{
		if (ray->ray_dir.y < 0)
			hit->hit_side = RAY_SIDE_SOUTH;
		else
			hit->hit_side = RAY_SIDE_NORTH;
	}
}

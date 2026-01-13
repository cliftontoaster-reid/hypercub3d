/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_hit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:47:12 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/13 15:22:59 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/raycast.h"
#include <math.h>

static void	init_hit_ctx(t_hit_ctx *c, t_raycast *ray,
		t_rayhit *hit, t_rayside side)
{
	c->ray = ray;
	c->hit = hit;
	c->side = side;
	if (side == RAY_SIDE_EAST || side == RAY_SIDE_WEST)
	{
		c->map_pos = ray->map_pos.x;
		c->player_pos = ray->player_pos.x;
		c->ray_dir = ray->ray_dir.x;
		c->side_dist = ray->side_dist.x;
		c->delta_dist = ray->delta_dist.x;
		c->step = ray->step.x;
	}
	else
	{
		c->map_pos = ray->map_pos.y;
		c->player_pos = ray->player_pos.y;
		c->ray_dir = ray->ray_dir.y;
		c->side_dist = ray->side_dist.y;
		c->delta_dist = ray->delta_dist.y;
		c->step = ray->step.y;
	}
}

static float	compute_hit_dist(t_hit_ctx *c)
{
	if (c->ray->fisheye_correction)
		return (c->side_dist - c->delta_dist);
	return ((c->map_pos - c->player_pos + (1 - c->step) / 2.0f) / c->ray_dir);
}

static float	compute_hit_pos(t_hit_ctx *c, float dist)
{
	if (c->side == RAY_SIDE_EAST || c->side == RAY_SIDE_WEST)
		return (c->ray->player_pos.y + dist * c->ray->ray_dir.y);
	return (c->ray->player_pos.x + dist * c->ray->ray_dir.x);
}

static bool	validate_hit(t_rayhit *hit)
{
	if (!isfinite(hit->dist) || !isfinite(hit->hit_pos))
	{
		hit->hit_side = RAY_SIDE_NONE;
		return (false);
	}
	return (true);
}

void	calculate_hit(t_raycast *ray, t_rayhit *hit, t_rayside side)
{
	t_hit_ctx	c;

	init_hit_ctx(&c, ray, hit, side);
	hit->dist = compute_hit_dist(&c);
	hit->hit_pos = compute_hit_pos(&c, hit->dist);
	if (!validate_hit(hit))
	{
		hit->hit_map = ray->map_pos;
		return ;
	}
	hit->hit_pos -= floorf(hit->hit_pos);
	if (side == RAY_SIDE_EAST || side == RAY_SIDE_WEST)
		set_side_communist(ray, side, hit);
	else
		set_side_capitalist(ray, side, hit);
	hit->hit_map = ray->map_pos;
}

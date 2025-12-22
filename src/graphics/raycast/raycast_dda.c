/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:59:33 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/22 14:10:53 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/raycast.h"

static void	set_side_communist(t_raycast *ray, t_rayside side, t_rayhit *hit)
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

static void	set_side_capitalist(t_raycast *ray, t_rayside side, t_rayhit *hit)
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

static void	perform_dda(t_raycast *ray, bool **map, t_rayside *side)
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

static void	calculate_hit(t_raycast *ray, t_rayhit *hit, t_rayside side)
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
	hit->hit_pos -= (int)hit->hit_pos;
	if (side == RAY_SIDE_EAST || side == RAY_SIDE_WEST)
		set_side_communist(ray, side, hit);
	else
		set_side_capitalist(ray, side, hit);
	hit->hit_map = ray->map_pos;
}

void	raycast_dda(t_raycast *ray, bool **map, t_rayhit *hit)
{
	t_rayside	side;

	perform_dda(ray, map, &side);
	calculate_hit(ray, hit, side);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_from_ctx_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:25:07 by mbores            #+#    #+#             */
/*   Updated: 2026/01/19 15:43:13 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/render.h"
#include <math.h>

#ifndef M_PI_2
# define M_PI_2 1.57079632679489661923
#endif

t_vec2	get_player_dir(float angle)
{
	return (vec2_new(cosf(angle - (float)M_PI_2),
			sinf(angle - (float)M_PI_2)));
}

void	setup_ray_direction(t_raycast *ray, t_ray_setup *setup)
{
	float	camera_x;

	camera_x = 2 * setup->x / (float)setup->screen_width - 1;
	ray->ray_dir.x = setup->player_dir.x + setup->plane.x * camera_x;
	ray->ray_dir.y = setup->player_dir.y + setup->plane.y * camera_x;
}

void	setup_x_step(t_raycast *ray, t_renderctx *ctx)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (ctx->pos.x - ray->map_pos.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map_pos.x + 1.0 - ctx->pos.x)
			* ray->delta_dist.x;
	}
}

void	setup_y_step(t_raycast *ray, t_renderctx *ctx)
{
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (ctx->pos.y - ray->map_pos.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map_pos.y + 1.0 - ctx->pos.y)
			* ray->delta_dist.y;
	}
}

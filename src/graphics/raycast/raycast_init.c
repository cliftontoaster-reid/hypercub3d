/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:48:24 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/22 14:14:26 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/raycast.h"
#include <math.h>
#include <stdlib.h>

static t_raycast	*allocate_raycast(t_rayoptions *options, t_table *map_table)
{
	t_raycast	*raycast;

	raycast = malloc(sizeof(t_raycast));
	if (!raycast)
		return (NULL);
	raycast->hit = false;
	raycast->map_table = map_table;
	raycast->player_pos = options->player_pos;
	raycast->fisheye_correction = options->fisheye_correction;
	raycast->map_pos = (t_vec2i){(int)options->player_pos.x,
		(int)options->player_pos.y};
	return (raycast);
}

static void	calculate_ray_and_delta(t_raycast *raycast, t_rayoptions *options,
		int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)options->win_width - 1;
	raycast->ray_dir.x = options->player_dir.x + options->camera_plane.x
		* camera_x;
	raycast->ray_dir.y = options->player_dir.y + options->camera_plane.y
		* camera_x;
	raycast->delta_dist.x = fabs(1 / raycast->ray_dir.x);
	raycast->delta_dist.y = fabs(1 / raycast->ray_dir.y);
}

static void	setup_x_step_side(t_raycast *raycast, t_rayoptions *options)
{
	if (raycast->ray_dir.x < 0)
	{
		raycast->step.x = -1;
		raycast->side_dist.x = (options->player_pos.x - raycast->map_pos.x)
			* raycast->delta_dist.x;
	}
	else
	{
		raycast->step.x = 1;
		raycast->side_dist.x = (raycast->map_pos.x + 1.0
				- options->player_pos.x) * raycast->delta_dist.x;
	}
}

static void	setup_y_step_side(t_raycast *raycast, t_rayoptions *options)
{
	if (raycast->ray_dir.y < 0)
	{
		raycast->step.y = -1;
		raycast->side_dist.y = (options->player_pos.y - raycast->map_pos.y)
			* raycast->delta_dist.y;
	}
	else
	{
		raycast->step.y = 1;
		raycast->side_dist.y = (raycast->map_pos.y + 1.0
				- options->player_pos.y) * raycast->delta_dist.y;
	}
}

t_raycast	*raycast_init(t_rayoptions *options, t_table *map_table, int x)
{
	t_raycast	*raycast;

	raycast = allocate_raycast(options, map_table);
	if (!raycast)
		return (NULL);
	calculate_ray_and_delta(raycast, options, x);
	setup_x_step_side(raycast, options);
	setup_y_step_side(raycast, options);
	return (raycast);
}

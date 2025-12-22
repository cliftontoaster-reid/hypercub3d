/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:34:35 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/22 14:12:26 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "map/table.h"
#include "utils/vec.h"
#include <stdbool.h>

typedef enum e_rayside
{
	RAY_SIDE_NONE = 0,
	RAY_SIDE_NORTH,
	RAY_SIDE_SOUTH,
	RAY_SIDE_EAST,
	RAY_SIDE_WEST
}				t_rayside;

typedef struct s_rayhit
{
	float		dist;
	float		hit_pos;
	t_rayside	hit_side;
	t_vec2i		hit_map;
}				t_rayhit;

typedef struct s_rayoptions
{
	bool		fisheye_correction;
	t_vec2		player_pos;
	t_vec2		player_dir;
	t_vec2		camera_plane;
	int			win_width;
}				t_rayoptions;

typedef struct s_raycast
{
	t_vec2		player_pos;
	t_vec2		ray_dir;
	t_vec2i		map_pos;
	t_vec2		side_dist;
	t_vec2		delta_dist;
	t_vec2i		step;
	bool		hit;
	t_table		*map_table;
	bool		fisheye_correction;
}				t_raycast;

t_raycast		*raycast_init(t_rayoptions *options, t_table *map_table, int x);
void			raycast_dda(t_raycast *raycast, bool **map, t_rayhit *rayhit);
void			raycast_free(t_raycast *raycast);

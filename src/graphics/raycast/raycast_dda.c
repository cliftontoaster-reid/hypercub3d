/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:59:33 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/06 14:59:48 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/raycast.h"
#include <sys/time.h> // For gettimeofday

#ifdef DEBUG

void	raycast_dda(t_renderctx *ctx, t_raycast *ray, bool **map, t_rayhit *hit)
{
	t_rayside		side;
	struct timeval	start_time;
	struct timeval	end_time;
	double			elapsed_time;
	long			time_diff[2];

	gettimeofday(&start_time, NULL);
	perform_dda(ray, map, &side);
	calculate_hit(ray, hit, side);
	gettimeofday(&end_time, NULL);
	time_diff[0] = end_time.tv_sec - start_time.tv_sec;
	time_diff[1] = end_time.tv_usec - start_time.tv_usec;
	elapsed_time = (double)time_diff[0] * 1e6 + (double)time_diff[1];
	rendertiming_add_ray(&ctx->timing, elapsed_time);
}
#else

void	raycast_dda(t_renderctx *ctx, t_raycast *ray, bool **map, t_rayhit *hit)
{
	t_rayside	side;

	(void)ctx;
	perform_dda(ray, map, &side);
	calculate_hit(ray, hit, side);
}
#endif

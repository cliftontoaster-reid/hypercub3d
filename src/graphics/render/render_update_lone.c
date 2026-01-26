/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_update_lone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:51:51 by mbores            #+#    #+#             */
/*   Updated: 2026/01/26 13:34:28 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/render.h"
#include <stdbool.h>
#include <time.h>

#ifndef CLOCK_MONOTONIC
# define CLOCK_MONOTONIC 1
#endif

static float	get_delta_time_sec(struct timespec *last_frame)
{
	struct timespec	current;
	float			delta;

	clock_gettime(CLOCK_MONOTONIC, &current);
	delta = (current.tv_sec - last_frame->tv_sec) + (current.tv_nsec
			- last_frame->tv_nsec) / 1000000000.0f;
	*last_frame = current;
	return (delta);
}

static void	wait_frame(struct timespec last_frame)
{
	struct timespec	current;
	struct timespec	wait_time;

	while (true)
	{
		clock_gettime(CLOCK_MONOTONIC, &current);
		wait_time.tv_sec = current.tv_sec - last_frame.tv_sec;
		wait_time.tv_nsec = current.tv_nsec - last_frame.tv_nsec;
		if (wait_time.tv_nsec < 0)
		{
			wait_time.tv_sec -= 1;
			wait_time.tv_nsec += 1000000000;
		}
		if (wait_time.tv_sec > 0 || wait_time.tv_nsec >= 16000000)
			break ;
	}
}

int	render_update_lone(t_renderctx *ctx)
{
	float	delta;

	delta = get_delta_time_sec(&ctx->last_frame_time);
	image_clear(ctx->buffer, rgb(0, 0, 0));
	render_update(ctx, delta);
	render_frame(ctx);
	render_present(ctx);
	wait_frame(ctx->last_frame_time);
	return (0);
}

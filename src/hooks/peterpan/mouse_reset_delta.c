/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_reset_delta.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:01:33 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/05 13:09:20 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks/peterpan.h"
#include "mlx.h"
#include "utils/vec.h"
#include <stdio.h>

// Resets the mouse movement delta by centering it and updating position
void	mouse_reset_delta(t_mouse_state *m, void *mlx, void *win,
		t_vec2i win_size)
{
	int	center_x;
	int	center_y;

	center_x = win_size.x / 2;
	center_y = win_size.y / 2;
	printf("[BEFORE WARP] Warping to: (%d, %d)\n", center_x, center_y);
	mlx_mouse_move(mlx, win, center_x, center_y);
	// Just update the stored position to the center without processing delta
	m->pos.x = (float)center_x;
	m->pos.y = (float)center_y;
	m->delta.x = 0.0f;
	m->delta.y = 0.0f;
	printf("[AFTER WARP] Position reset to: (%d, %d)\n", center_x, center_y);
}

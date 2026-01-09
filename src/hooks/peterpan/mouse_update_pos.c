/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_update_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:04:28 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/22 16:04:36 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks/peterpan.h"
#include "mlx.h"
#include <stdio.h>

// Updates the mouse position and calculates delta
void	mouse_update_pos(t_mouse_state *m, int x, int y)
{
	t_vec2	new_pos;

	printf("Mouse moved to (%d, %d) - old_pos=(%.0f, %.0f)\n", x, y, m->pos.x,
		m->pos.y);
	new_pos.x = (float)x;
	new_pos.y = (float)y;
	m->delta.x = new_pos.x - m->pos.x;
	m->delta.y = new_pos.y - m->pos.y;
	printf("  -> delta=(%.2f, %.2f)\n", m->delta.x, m->delta.y);
	m->pos = new_pos;
}

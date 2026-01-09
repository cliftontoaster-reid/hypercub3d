/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:53:09 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/22 16:05:50 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks/peterpan.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

static int	mouse_move_callback(int x, int y, t_mouse_state *m)
{
	mouse_update_pos(m, x, y);
	return (0);
}

static int	mouse_yes(int button, int x, int y, t_mouse_state *m)
{
	(void)x;
	(void)y;
	mouse_update_button(m, (unsigned char)button, true);
	return (0);
}

static int	mouse_no(int button, int x, int y, t_mouse_state *m)
{
	(void)x;
	(void)y;
	mouse_update_button(m, (unsigned char)button, false);
	return (0);
}

// Initializes the mouse state
t_mouse_state	*mouse_init(void *mlx, void *win)
{
	t_mouse_state	*m;

	(void)mlx;
	m = (t_mouse_state *)malloc(sizeof(t_mouse_state));
	if (!m)
		return (NULL);
	ft_bzero(m, sizeof(t_mouse_state));
	mlx_hook(win, EVENT_MOUSE_MOVE, MASK_MOUSE_MOVE, mouse_move_callback, m);
	mlx_hook(win, EVENT_MOUSE_PRESS, MASK_MOUSE_PRESS, mouse_yes, m);
	mlx_hook(win, EVENT_MOUSE_RELEASE, MASK_MOUSE_RELEASE, mouse_no, m);
	m->mlx = mlx;
	m->win = win;
	return (m);
}

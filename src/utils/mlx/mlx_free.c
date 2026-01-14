/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:08:46 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/14 13:07:25 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/mlx.h"

void	free_window_list(t_my_xvar *mlx)
{
	t_my_win_list	*w;
	t_my_win_list	*next;

	if (mlx->win_list)
	{
		w = mlx->win_list;
		while (w)
		{
			next = w->next;
			if (mlx->display && w->window)
				XDestroyWindow(mlx->display, w->window);
			if (mlx->display && w->gc)
				XFreeGC(mlx->display, w->gc);
			free(w);
			w = next;
		}
	}
}

void	mlx_free(void *ptr)
{
	t_my_xvar		*mlx;

	if (!ptr)
		return ;
	mlx = (t_my_xvar *)ptr;
	free_window_list(mlx);
	if (mlx->display && mlx->private_cmap)
		XFreeColormap(mlx->display, mlx->cmap);
	if (mlx->display)
	{
		if (mlx->do_flush)
			XFlush(mlx->display);
		XCloseDisplay(mlx->display);
	}
	free(mlx);
}

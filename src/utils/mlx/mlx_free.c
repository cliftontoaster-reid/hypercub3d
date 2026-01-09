/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:08:46 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/09 15:12:32 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/mlx.h"

void	mlx_free(void *ptr)
{
	t_my_xvar		*mlx;
	t_my_win_list	*w;
	t_my_win_list	*next;

	if (!ptr)
		return ;
	mlx = (t_my_xvar *)ptr;
	/* Destroy all windows and their GCs */
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
	/* Free private colormap if created */
	if (mlx->display && mlx->private_cmap)
		XFreeColormap(mlx->display, mlx->cmap);
	/* Flush and close display */
	if (mlx->display)
	{
		if (mlx->do_flush)
			XFlush(mlx->display);
		XCloseDisplay(mlx->display);
	}
	/* Finally free the mlx structure */
	free(mlx);
}
